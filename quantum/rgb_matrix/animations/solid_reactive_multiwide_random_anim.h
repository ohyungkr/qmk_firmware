#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_MULTIWIDE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static hsv_t SOLID_REACTIVE_MULTIWIDE_RANDOM_math(hsv_t hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;

    // 타건 시점 시드로 무작위 H(색상)와 무작위 S(채도) 선정
    hsv.h = (uint8_t)(tick * 167 + 53);                // Random H (0~255)
    hsv.s = (uint8_t)(128 + ((tick * 97 + 31) % 128)); // Random S (128~255 풍부한 채도)
    hsv.v = qadd8(hsv.v, 255 - effect);                // V(밝기)만 시간이 지나면서 Fadeout

    return hsv;
}

bool SOLID_REACTIVE_MULTIWIDE_RANDOM(effect_params_t* params) {
    return effect_runner_reactive_splash(0, params, &SOLID_REACTIVE_MULTIWIDE_RANDOM_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
