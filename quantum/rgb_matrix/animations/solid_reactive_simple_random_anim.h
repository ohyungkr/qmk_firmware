#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_SIMPLE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static hsv_t SOLID_REACTIVE_SIMPLE_RANDOM_math(hsv_t hsv, uint16_t offset) {
    if (offset > 255) offset = 255;

    // g_last_hit_tracker.tick[0]은 프레임마다 증가하는 경과 시간이므로,
    // (g_rgb_timer - tick) 연산으로 키가 눌린 '고정 시각(Timestamp)'을 도출합니다.
    uint16_t hit_tick = g_last_hit_tracker.tick[0];
    uint16_t press_timestamp = g_rgb_timer - hit_tick;

    // 키를 누른 그 시점의 고정 시드로 H(색상)와 S(채도) 결정 (소멸 중 색상 변동 전혀 없음)
    hsv.h = (uint8_t)(press_timestamp * 167 + 53);
    hsv.s = (uint8_t)(128 + ((press_timestamp * 97 + 31) % 128));
    hsv.v = scale8(255 - offset, hsv.v); // V(밝기)만 255 -> 0으로 Fadeout

    return hsv;
}

bool SOLID_REACTIVE_SIMPLE_RANDOM(effect_params_t* params) {
    return effect_runner_reactive(params, &SOLID_REACTIVE_SIMPLE_RANDOM_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
