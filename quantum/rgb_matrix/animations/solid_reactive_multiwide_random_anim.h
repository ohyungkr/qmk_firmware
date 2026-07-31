#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_MULTIWIDE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern uint8_t g_hit_rand_hues[256];

bool SOLID_REACTIVE_MULTIWIDE_RANDOM(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t count = g_last_hit_tracker.count;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        hsv_t hsv = rgb_matrix_config.hsv;
        hsv.v     = 0;

        for (uint8_t j = 0; j < count; j++) {
            int16_t  dx   = g_led_config.point[i].x - g_last_hit_tracker.x[j];
            int16_t  dy   = g_led_config.point[i].y - g_last_hit_tracker.y[j];
            uint8_t  dist = sqrt16(dx * dx + dy * dy);
            uint16_t tick = scale16by8(g_last_hit_tracker.tick[j], qadd8(rgb_matrix_config.speed, 1));

            uint16_t effect = tick + dist * 5;
            if (effect < 255) {
                // 해당 타건 이벤트 j 시점의 rand() 색상 1개로 파동 유지
                hsv.h = g_hit_rand_hues[j];
                hsv.v = qadd8(hsv.v, 255 - effect);
            }
        }

        hsv.v     = scale8(hsv.v, rgb_matrix_config.hsv.v);
        rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_region_set_color(params->region, i, rgb.r, rgb.g, rgb.b);
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
