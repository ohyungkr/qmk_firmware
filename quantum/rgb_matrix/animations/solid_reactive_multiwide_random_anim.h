#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_MULTIWIDE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static hsv_t SOLID_REACTIVE_MULTIWIDE_RANDOM_math(hsv_t hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;

    // (g_rgb_timer - tick)으로 타건 시점의 고정 시각(Timestamp) 도출
    uint16_t press_timestamp = g_rgb_timer - tick;

    // 타건 시점의 고정 시드로 H(색상)와 S(채도) 결정 (파동 소멸 중 색상 변동 전혀 없음)
    hsv.h = (uint8_t)(press_timestamp * 167 + 53);
    hsv.s = (uint8_t)(128 + ((press_timestamp * 97 + 31) % 128));
    hsv.v = qadd8(hsv.v, 255 - effect); // V(밝기)만 Fadeout

    return hsv;
}

bool SOLID_REACTIVE_MULTIWIDE_RANDOM(effect_params_t* params) {
    return effect_runner_reactive_splash(0, params, &SOLID_REACTIVE_MULTIWIDE_RANDOM_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
