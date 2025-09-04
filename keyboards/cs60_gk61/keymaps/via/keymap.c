// Copyright 2023 NaturalZh (@NaturalZh)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layer_names {
    _BS,  // base
    _GM,  // game
    _SP,  // space
    _FN,  // function
    _WH,  // wheel
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┐
     * │ESC│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │  Bksp │
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┤
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │  \  │
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┤
     * │ Ctrl │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │  Enter │
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────────┤
     * │ Shift  │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │    Shift │
     * ├────┬───┴┬──┴─┬─┴───┴───┴──┬┴───┴───┴──┬┴───┼───┴┬────┬────┤
     * │Ctrl│GUI │Alt │    Space   │  SpaceFn  │ Alt│ MO │Menu│Ctrl│
     * └────┴────┴────┴────────────┴───────────┴────┴────┴────┴────┘
     */
    [_BS] = LAYOUT_60_ansi(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
LT(_FN, KC_TAB), KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, LT(_FN, KC_BSLS),
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT,          KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT,
        KC_LCTL, KC_LGUI, KC_LALT,           LT(_SP, KC_SPC), LT(_SP, KC_SPC),           LT(_WH, KC_RALT), MO(_FN), KC_APP,  KC_RCTL
    ),
    [_GM] = LAYOUT_60_ansi(
        _______, _______, _______, _______, KC_4,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  _______, QK_KB_0, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_BSLS,
        _______, QK_KB_1, QK_KB_2, QK_KB_3, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                   KC_SPC,  _______,                            KC_RALT, _______, _______, _______
    ),
    [_SP] = LAYOUT_60_ansi(
        KC_GRV,  0x0d1e,  0x0d1f,  0x0d20,  0x0d21,  _______, _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_DEL,
        _______, _______, _______, _______, _______, _______, _______, KC_PGUP, KC_UP,   KC_PGDN, _______, _______, _______, TO(_GM),
        _______, _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, KC_END,  _______, _______, _______, _______,          _______,
        _______, _______, _______,                   _______, _______,                            _______, _______, _______, _______
    ),
    [_FN] = LAYOUT_60_ansi(
        KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_F13,
        _______, RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_PSCR, _______, KC_PAUSE,TO(_BS),
        _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, KC_BTN4, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, KC_BTN5, _______, _______, _______, _______,          _______,
        KC_CAPS, 0x5d61,  _______,                   _______, KC_BTN1,                            _______, _______, _______, _______
    ),
    [_WH] = LAYOUT_60_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_BTN3, KC_WH_U, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______,                   _______, KC_SPC,                             _______, _______, _______, _______
    )
};

// Snap Tap / SOCD
static const int SOCD_KEY[2][2] = {
    { KC_W, KC_S },
    { KC_A, KC_D }
};

bool socd_key_state[2][2] = { {0,0},{0,0}};

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode >= QK_KB_0 && keycode <= QK_KB_3) {
        uint8_t key = keycode - QK_KB_0;
        uint8_t k_group = key&1;
        uint8_t k_num = key>>1;
        uint8_t k_op_num = k_num?0:1;
        if (record->event.pressed) {
            socd_key_state[k_group][k_num] = 1;
            if (socd_key_state[k_group][k_op_num]) {
                unregister_code(SOCD_KEY[k_group][k_op_num]);
            }
            register_code(SOCD_KEY[k_group][k_num]);
        } else {
            socd_key_state[k_group][k_num] = 0;
            unregister_code(SOCD_KEY[k_group][k_num]);
            if (socd_key_state[k_group][k_op_num]) {
                register_code(SOCD_KEY[k_group][k_op_num]);
            }
        }
    }
}
