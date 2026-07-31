#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_MULTIWIDE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static hsv_t SOLID_REACTIVE_MULTIWIDE_RANDOM_math(hsv_t hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;
    // 파동 위치 및 타임스탬프 기반 무작위 HUE 생성
    hsv.h = (uint8_t)(g_rgb_timer * 13 + dist * 9 + (dx * 3 ^ dy * 5));
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

bool SOLID_REACTIVE_MULTIWIDE_RANDOM(effect_params_t* params) {
    return effect_runner_reactive_splash(0, params, &SOLID_REACTIVE_MULTIWIDE_RANDOM_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
