#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_SIMPLE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static hsv_t SOLID_REACTIVE_SIMPLE_RANDOM_math(hsv_t hsv, uint16_t offset) {
    if (offset > 255) offset = 255;
    // 사용자가 선택한 hsv.h 대신 Rand() 시드 색상 대입 (다른 로직은 SOLID_REACTIVE_SIMPLE과 동일)
    hsv.h = (uint8_t)(g_last_hit_tracker.tick[0] * 167 + 53);
    hsv.v = scale8(255 - offset, hsv.v);
    return hsv;
}

bool SOLID_REACTIVE_SIMPLE_RANDOM(effect_params_t* params) {
    return effect_runner_reactive(params, &SOLID_REACTIVE_SIMPLE_RANDOM_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
