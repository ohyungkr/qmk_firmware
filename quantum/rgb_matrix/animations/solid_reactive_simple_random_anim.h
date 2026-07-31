#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_SIMPLE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

bool SOLID_REACTIVE_SIMPLE_RANDOM(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / qadd8(rgb_matrix_config.speed, 1);
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        uint16_t tick = max_tick;
        uint16_t raw_hit_tick = 0;

        // 가장 최근 타건 틱 찾기
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.index[j] == i && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                raw_hit_tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        uint16_t offset = scale16by8(tick, qadd8(rgb_matrix_config.speed, 1));
        if (offset > 255) offset = 255;

        hsv_t hsv = rgb_matrix_config.hsv;
        if (offset < 255 && tick < max_tick) {
            // 타건 시점의 고정 틱과 LED 인덱스를 조합한 고정 무작위 HUE (Fade 중 색상 변동 없음)
            hsv.h = (uint8_t)(raw_hit_tick * 167 + i * 97 + 53);
            hsv.v = scale8(255 - offset, hsv.v);
        } else {
            hsv.v = 0;
        }

        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_region_set_color(params->region, i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
