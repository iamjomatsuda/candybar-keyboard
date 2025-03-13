
// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H


// layer names
enum layer_names {
    _DEFAULT,
    _NUMBERS,
    _ARROWS,
    _FUNCTION
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┐
     * │ESC│WHA│TEV│VER│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬───┬───┬───┬───┬───┬───┬───┐
     * │ TAB │ Q │ W │ F │ P │ G │ J │ L │ U │ Y │ ; │
     * ├─────┼───┼───┼───┼───┼───┼───┼───┼───┼───┼───┤
     * │ BSPC│ A │ R │ S │ T │ D │ H │ N │ E │ I │ O │
     * ├─────┼───┼───┼───┼───┼───┼───┤───┼───┼───┴───┤
     * │ LSFT│ Z │ X │ C │ V │ B │ K │ M │ / │ ENTER │
     * ├─────┼───┼───┼───┴───┴───┴───┴───┴───┴┬──────┘
     * │ LCTL│MOD│ALT│         SPACE          │
     * └─────┴───┴───┴────────────────────────┘
     */


    [0] = LAYOUT_ortho_4_2x10_9_4(
        KC_ESC,    KC_PSCR,   KC_CAPS,   QK_LLCK,
        KC_TAB,    KC_Q,      KC_W,      KC_F,      KC_P,      KC_G,      KC_J,      KC_L,      KC_U,      KC_Y,      KC_SCLN,
        KC_BSPC,   KC_A,      KC_R,      KC_S,      KC_T,      KC_D,      KC_H,      KC_N,      KC_E,      KC_I,      KC_O,
        KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_K,      KC_M,      KC_SLSH,   LT(1, KC_ENT),
        KC_LCTL,   KC_LGUI,   KC_LALT,   KC_SPC
    ),
    [1] = LAYOUT_ortho_4_2x10_9_4(
        _______,   _______,   _______,   _______,
        _______,   KC_GRV,    KC_MINS,   KC_EQL,    _______,   _______,   KC_QUOT,   KC_LBRC,   KC_RBRC,   KC_BSLS,   _______,
        KC_DEL,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,
        _______,   _______,   _______,   _______,   _______,   TG(2),   KC_COMM,   KC_DOT,    _______,   _______,
        _______,   _______,   _______,   LT(2, KC_SPC)
    ),
    [2] = LAYOUT_ortho_4_2x10_9_4(
        _______,   _______,   _______,   _______,
        _______,   _______,   KC_UP,     _______,   _______,   _______,   _______,   KC_UP,     _______,   _______,   _______,
        _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   _______,   _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,   _______,   _______,
        _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   MO(3),     _______,
        _______,   _______,   _______,   _______
    ),
    [3] = LAYOUT_ortho_4_2x10_9_4(
        _______,   _______,   _______,   _______,
        _______,   KC_VOLD,   KC_MUTE,   KC_VOLU,   KC_MPRV,   KC_MPLY,   KC_MNXT,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,
        _______,   KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,
        _______,   KC_F11,    KC_F12,    XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   XXXXXXX,   _______,   _______,
        _______,   _______,   _______,   _______
    )
};

// OLED things
#ifdef OLED_ENABLE

// draw
bool oled_task_user(void) {

    // CAPS
    oled_set_cursor(10,1);
    oled_write("CAPS:", false);

    // caps
    oled_set_cursor(15,1);
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("ON! "): PSTR("OFF."), false);

    // show layers
    oled_set_cursor(0,1);
    switch (get_highest_layer(layer_state)) {
        case _DEFAULT :
            oled_write("ALPHA ", false);
            break;
        case _NUMBERS :
            oled_write("NUMBER", false);
            break;
        case _ARROWS :
            oled_write("ARROW ", false);

            break;
        case _FUNCTION :
            oled_write("FUNC  ", false);
            break;
    }


    return false;
}

 #endif
