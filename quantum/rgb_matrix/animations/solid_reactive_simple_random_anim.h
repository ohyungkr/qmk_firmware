#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_SIMPLE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern uint8_t g_key_rand_hues[DRIVER_LED_TOTAL];

static hsv_t SOLID_REACTIVE_SIMPLE_RANDOM_math(hsv_t hsv, uint16_t offset) {
    if (offset > 255) offset = 255;
    // 사용자가 선택한 hsv.h 대신, 타건 시 딱 1번 선택되어 고정된 rand() % 256 색상 대입
    hsv.h = g_key_rand_hues[g_last_hit_tracker.index[0]];
    hsv.v = scale8(255 - offset, hsv.v);
    return hsv;
}

bool SOLID_REACTIVE_SIMPLE_RANDOM(effect_params_t* params) {
    return effect_runner_reactive(params, &SOLID_REACTIVE_SIMPLE_RANDOM_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
