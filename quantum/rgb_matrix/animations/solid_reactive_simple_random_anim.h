#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_SIMPLE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern uint8_t random_key_hue[DRIVER_LED_TOTAL];
extern uint8_t random_key_val[DRIVER_LED_TOTAL];

bool SOLID_REACTIVE_SIMPLE_RANDOM(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint8_t fade_step = qadd8(rgb_matrix_config.speed >> 3, 3); // fade 감쇄 속도

    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();

        if (random_key_val[i] > 0) {
            hsv_t hsv;
            hsv.h = random_key_hue[i]; // 타건 시 rand()로 부여된 단 1개의 고정 무작위 HUE
            hsv.s = 255;
            hsv.v = scale8(random_key_val[i], rgb_matrix_config.hsv.v);

            rgb_t rgb = rgb_matrix_hsv_to_rgb(hsv);
            rgb_matrix_region_set_color(params->region, i, rgb.r, rgb.g, rgb.b);

            // 매 프레임마다 밝기만 감소 (Fade-out)
            if (random_key_val[i] > fade_step) {
                random_key_val[i] -= fade_step;
            } else {
                random_key_val[i] = 0;
            }
        } else {
            rgb_matrix_region_set_color(params->region, i, 0, 0, 0);
        }
    }
    return rgb_matrix_check_finished_leds(led_max);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
