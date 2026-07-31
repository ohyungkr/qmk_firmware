#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_MULTIWIDE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

extern uint8_t g_hit_rand_hues[256];

static hsv_t SOLID_REACTIVE_MULTIWIDE_RANDOM_math(hsv_t hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist * 5;
    if (effect > 255) effect = 255;
    // 사용자가 선택한 hsv.h 대신, 타건 시 딱 1번 선택되어 고정된 rand() % 256 색상 대입
    hsv.h = g_hit_rand_hues[g_last_hit_tracker.count > 0 ? (g_last_hit_tracker.count - 1) : 0];
    hsv.v = qadd8(hsv.v, 255 - effect);
    return hsv;
}

bool SOLID_REACTIVE_MULTIWIDE_RANDOM(effect_params_t* params) {
    return effect_runner_reactive_splash(0, params, &SOLID_REACTIVE_MULTIWIDE_RANDOM_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
