#ifdef RGB_MATRIX_KEYREACTIVE_ENABLED
RGB_MATRIX_EFFECT(my_solid_reactive_multiwide_col)
RGB_MATRIX_EFFECT(my_solid_reactive_col)
RGB_MATRIX_EFFECT(my_solid_seto)
RGB_MATRIX_EFFECT(my_solid_seto2)

#    ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV my_solid_reactive_multiwide_col_math(HSV hsv, int16_t dx, int16_t dy, uint8_t dist, uint16_t tick) {
    uint16_t effect = tick + dist;
    dx              = dx < 0 ? dx * -1 : dx;
    dx              = dx * 16 > 255 ? 255 : dx * 16;
    effect += dx;
    if (effect > 255) effect = 255;
    hsv.v = qadd8(hsv.v, 255 - effect);
    // hsv.h += qsub8(130, effect);
    return hsv;
}

bool my_solid_reactive_multiwide_col(effect_params_t* params) {
    return effect_runner_reactive_splash(0, params, &my_solid_reactive_multiwide_col_math);
}


bool my_solid_reactive_col(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);

    uint16_t max_tick = 65535 / rgb_matrix_config.speed;
    for (uint8_t i = led_min; i < led_max; i++) {
        RGB_MATRIX_TEST_LED_FLAGS();
        HSV hsv = rgb_matrix_config.hsv;
        uint16_t tick = max_tick;
        // Reverse search to find most recent key hit
        for (int8_t j = g_last_hit_tracker.count - 1; j >= 0; j--) {
            if (g_last_hit_tracker.x[j] == g_led_config.point[i].x && g_last_hit_tracker.tick[j] < tick) {
                tick = g_last_hit_tracker.tick[j];
                break;
            }
        }

        uint16_t offset = scale16by8(tick, rgb_matrix_config.speed);
        hsv.h += qsub8(130, offset);
        RGB      rgb    = rgb_matrix_hsv_to_rgb(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return led_max < DRIVER_LED_TOTAL;
}

bool my_solid_seto(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, RGB_BLACK);
    }
    rgb_matrix_set_color(9, RGB_DARKRED);
    rgb_matrix_set_color(10, RGB_DARKRED);
    rgb_matrix_set_color(37, RGB_DARKRED);
    rgb_matrix_set_color(44, RGB_DARKRED);
    rgb_matrix_set_color(45, RGB_DARKRED);
    rgb_matrix_set_color(48, RGB_DARKRED);
    rgb_matrix_set_color(75, RGB_DARKRED);
    rgb_matrix_set_color(74, RGB_DARKRED);
    rgb_matrix_set_color(73, RGB_DARKRED);
    rgb_matrix_set_color(72, RGB_DARKRED);
    rgb_matrix_set_color(71, RGB_DARKRED);
    rgb_matrix_set_color(82, RGB_DARKRED);



    rgb_matrix_set_color(17, RGB_DARKRED);
    rgb_matrix_set_color(29, RGB_DARKRED);
    rgb_matrix_set_color(54, RGB_DARKRED);
    rgb_matrix_set_color(56, RGB_DARKRED);
    rgb_matrix_set_color(66, RGB_DARKRED);
    rgb_matrix_set_color(65, RGB_DARKRED);
    rgb_matrix_set_color(64, RGB_DARKRED);
    rgb_matrix_set_color(91, RGB_DARKRED);
    rgb_matrix_set_color(103, RGB_DARKRED);


    return led_max < DRIVER_LED_TOTAL;
}

bool my_solid_seto2(effect_params_t* params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, RGB_BLACK);
    }
    rgb_matrix_set_color(5, RGB_DARKRED);
    rgb_matrix_set_color(6, RGB_DARKRED);
    rgb_matrix_set_color(7, RGB_DARKRED);
    rgb_matrix_set_color(8, RGB_DARKRED);
    rgb_matrix_set_color(9, RGB_DARKRED);
    rgb_matrix_set_color(10, RGB_DARKRED);
    rgb_matrix_set_color(11, RGB_DARKRED);
    rgb_matrix_set_color(13, RGB_DARKRED);
    rgb_matrix_set_color(17, RGB_DARKRED);
    rgb_matrix_set_color(18, RGB_DARKRED);
    rgb_matrix_set_color(19, RGB_DARKRED);
    rgb_matrix_set_color(21, RGB_DARKRED);



    rgb_matrix_set_color(38, RGB_DARKRED);
    rgb_matrix_set_color(37, RGB_DARKRED);
    rgb_matrix_set_color(32, RGB_DARKRED);
    rgb_matrix_set_color(29, RGB_DARKRED);
    rgb_matrix_set_color(26, RGB_DARKRED);

    rgb_matrix_set_color(43, RGB_DARKRED);
    rgb_matrix_set_color(44, RGB_DARKRED);
    rgb_matrix_set_color(46, RGB_DARKRED);
    rgb_matrix_set_color(47, RGB_DARKRED);
    rgb_matrix_set_color(48, RGB_DARKRED);
    rgb_matrix_set_color(51, RGB_DARKRED);
    rgb_matrix_set_color(54, RGB_DARKRED);
    rgb_matrix_set_color(57, RGB_DARKRED);

    rgb_matrix_set_color(77, RGB_DARKRED);
    rgb_matrix_set_color(73, RGB_DARKRED);
    rgb_matrix_set_color(68, RGB_DARKRED);
    rgb_matrix_set_color(65, RGB_DARKRED);
    rgb_matrix_set_color(62, RGB_DARKRED);

    rgb_matrix_set_color(80, RGB_DARKRED);
    rgb_matrix_set_color(81, RGB_DARKRED);
    rgb_matrix_set_color(82, RGB_DARKRED);
    rgb_matrix_set_color(84, RGB_DARKRED);
    rgb_matrix_set_color(85, RGB_DARKRED);
    rgb_matrix_set_color(86, RGB_DARKRED);
    rgb_matrix_set_color(87, RGB_DARKRED);
    rgb_matrix_set_color(88, RGB_DARKRED);
    rgb_matrix_set_color(89, RGB_DARKRED);
    rgb_matrix_set_color(90, RGB_DARKRED);
    rgb_matrix_set_color(91, RGB_DARKRED);
    rgb_matrix_set_color(92, RGB_DARKRED);
    rgb_matrix_set_color(93, RGB_DARKRED);
    rgb_matrix_set_color(94, RGB_DARKRED);


    return led_max < DRIVER_LED_TOTAL;
}

#    endif      // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
#endif          // RGB_MATRIX_KEYREACTIVE_ENABLED
