#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_SIMPLE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static hsv_t SOLID_REACTIVE_SIMPLE_RANDOM_math(hsv_t hsv, uint16_t offset) {
    if (offset > 255) offset = 255;
    // 타건 시점 및 오프셋 기반 무작위 HUE 생성
    hsv.h = (uint8_t)(g_rgb_timer * 11 + offset * 7);
    hsv.v = scale8(255 - offset, hsv.v);
    return hsv;
}

bool SOLID_REACTIVE_SIMPLE_RANDOM(effect_params_t* params) {
    return effect_runner_reactive(params, &SOLID_REACTIVE_SIMPLE_RANDOM_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
