/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H


enum layers {
    QWERTY = 0,
    NUM,
    SYM,
    FUNCTION,
};


#define CTL_LCBR MT(MOD_LCTL, KC_LCBR)
#define ALT_LBRC MT(MOD_LALT, KC_LBRC)
#define GUI_DEL  MT(MOD_LGUI, KC_DEL)
#define SFT_ESC  MT(MOD_LSFT, KC_ESC)
#define NUM_TAB  LT(NUM, KC_TAB)

#define CTL_ENT  MT(MOD_RCTL, KC_ENT)
#define CTL_0    MT(MOD_RCTL, KC_0)
#define GUI_SPC  MT(MOD_RGUI, KC_SPC)
#define SYM_BSPC LT(SYM, KC_BSPC)
#define ALT_RBRC MT(MOD_RALT, KC_RBRC)
#define SFT_RCBR MT(MOD_RSFT, KC_RCBR)

const uint16_t PROGMEM lbkt[] = {KC_U, KC_J, COMBO_END};
const uint16_t PROGMEM lbrc[] = {KC_J, KC_M, COMBO_END};
const uint16_t PROGMEM lpar[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM rbkt[] = {KC_I, KC_K, COMBO_END};
const uint16_t PROGMEM rbrc[] = {KC_K, KC_COMM, COMBO_END};
const uint16_t PROGMEM rpar[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM lmeh[] = {GUI_SPC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM rmeh[] = {GUI_SPC, KC_RBRC, COMBO_END};
const uint16_t PROGMEM lfn[] = {CTL_ENT, KC_RPRN, COMBO_END};
const uint16_t PROGMEM rfn[] = {CTL_ENT, KC_RPRN, COMBO_END};

combo_t key_combos[] = {
    COMBO(lbkt, KC_LBRC),
    COMBO(lbrc, KC_LCBR),
    COMBO(lpar, KC_LPRN),
    COMBO(rbkt, KC_RBRC),
    COMBO(rbrc, KC_RCBR),
    COMBO(rpar, KC_RPRN),
    COMBO(rmeh, KC_MEH),
    COMBO(rfn, MO(FUNCTION)),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [QWERTY] = LAYOUT(
      _______,
         KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,                                             KC_Y,     KC_U,     KC_I,     KC_O,    KC_P,
      _______,  _______,
         KC_A,     KC_S,     KC_D,     KC_F,     KC_G,                                             KC_H,     KC_J,     KC_K,     KC_L,  KC_SCLN,
      _______,  _______,
         KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,  KC_LBRC,  KC_LPRN,  KC_RPRN,  KC_RBRC,     KC_N,     KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,
      _______,
                         CTL_LCBR, ALT_LBRC,  GUI_DEL,  SFT_ESC,  NUM_TAB,  CTL_ENT,  GUI_SPC, SYM_BSPC, ALT_RBRC, SFT_RCBR
    ),

    [NUM] = LAYOUT(
      _______,
      _______,  _______,  _______,  _______,  _______,                                           KC_EQL,     KC_7,     KC_8,     KC_9,  KC_ASTR,
      _______,  _______,
      _______,  _______,  _______,  _______,  _______,                                          KC_UNDS,     KC_4,     KC_5,     KC_6,  KC_PLUS,
      _______,  _______,
      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   KC_DOT,     KC_1,     KC_2,     KC_3,  KC_MINS,
      _______,
                          _______,  _______,  _______,  _______,  _______,    CTL_0,  _______,  _______,  _______,  _______
    ),

    [SYM] = LAYOUT(
      _______,
      KC_EXLM,    KC_AT,  KC_HASH,   KC_DLR,  KC_PERC,                                          KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,
      _______,  _______,
       KC_GRV,  KC_MINS,   KC_EQL,  KC_QUOT,  KC_BSLS,                                          KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT,  _______,
      _______,  _______,
      KC_TILD,  KC_UNDS,  KC_PLUS,  KC_DQUO,  KC_PIPE,  _______,  _______,  _______,  _______,  KC_HOME,  KC_PGDN,  KC_PGUP,   KC_END,  _______,
      _______,
                          _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),

    [FUNCTION] = LAYOUT(
      _______,
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,                                          KC_VOLU,  _______,  _______,  _______,  _______,
      _______,  _______,
        KC_F6,    KC_F7,    KC_F8,    KC_F9,   KC_F10,                                          KC_VOLD,  KC_MPRV,  KC_MPLY,  KC_MNXT,   RGB_TOG,
      _______,  _______,
       KC_F11,   KC_F12,   KC_F13,   KC_F14,   KC_F15,  _______,  _______,  _______,  _______,  KC_MUTE,  RGB_SAI,  RGB_HUI,  RGB_VAI,   RGB_MOD,
      _______,
                          _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______
    ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case NUM:
                oled_write_P(PSTR("Num\n"), false);
                break;
            case SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif
