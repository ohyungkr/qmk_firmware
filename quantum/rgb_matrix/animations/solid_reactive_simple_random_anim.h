#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
#    ifdef ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
RGB_MATRIX_EFFECT(SOLID_REACTIVE_SIMPLE_RANDOM)
#        ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static hsv_t SOLID_REACTIVE_SIMPLE_RANDOM_math(hsv_t hsv, uint16_t offset) {
    if (offset > 255) offset = 255;

    // 타건 시점 시드로 무작위 H(색상)와 무작위 S(채도) 선정
    uint16_t hit_tick = g_last_hit_tracker.tick[0];
    hsv.h = (uint8_t)(hit_tick * 167 + 53);                // Random H (0~255)
    hsv.s = (uint8_t)(128 + ((hit_tick * 97 + 31) % 128)); // Random S (128~255 풍부한 채도)
    hsv.v = scale8(255 - offset, hsv.v);                   // V(밝기)만 시간이 지나면서 Fadeout

    return hsv;
}

bool SOLID_REACTIVE_SIMPLE_RANDOM(effect_params_t* params) {
    return effect_runner_reactive(params, &SOLID_REACTIVE_SIMPLE_RANDOM_math);
}

#        endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#    endif     // ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE_RANDOM
#endif         // RGB_MATRIX_KEYREACTIVE_ENABLED
