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


#ifdef __INTELLISENSE__
    #include "../../rev1/config.h"
    #include "../../rev1/rev1.h"
    #include "config.h"
    enum dynamic_macro_keycodes {
        DYN_REC_START1 = DYNAMIC_MACRO_RANGE,
        DYN_REC_START2,
        DYN_REC_STOP,
        DYN_MACRO_PLAY1,
        DYN_MACRO_PLAY2,
    };
    #define QMK_KEYBOARD_H "rev1.h"
#endif

#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layers {
    _QWERTZ = 0,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: QWERTZ
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   ESC  |   Q  |   W  |   E  |   R  |   T  |                              |   Z  |   U  |   I  |   O  |   P  |  +  *  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Tab  |   A  |   S  |  D   |   F  |   G  |                              |   H  |   J  |   K  |   L  |      |  # '   |
 * |--------+------+------+------+------+------+----------.-----.  ,-------------+------+------+------+------+------+-----|
 * | LShift |   Y  |   X  |   C  |   V  |   B  |LALT+TAB|LShift|  |LShift|LShift|   N  |   M  | ,  ; | . :  | -  _ | Del  |
 * `----------------------+------+------+------+------+--------|  |------+------+------+------+------+----------------------'
 *                        | GUI  | CTRL | Space| Bksp | Enter  |  |      | LArrow| DArrow| UArrow| RArrow|
 *                        |      |      | Alt  |      | Raise  |  | Lower|       |       |       |       |
 *                        `------------------------------------'  `--------------------------------------'
 */
    [_QWERTZ] = LAYOUT(
      KC_ESC,  KC_Q,    KC_W,     KC_E,                 KC_R,               KC_T,                                DE_Z,                KC_U,                 KC_I,     KC_O,   KC_P,    DE_PLUS,
      KC_TAB,  KC_A,    KC_S,     KC_D,                 KC_F,               KC_G,                                KC_H,                KC_J,                 KC_K,     KC_L,   _______, DE_HASH,
      KC_LSFT, DE_Y,    KC_X,     KC_C,                 KC_V,               KC_B,                LALT(KC_TAB),   KC_LSFT,             LT(_ADJUST, _______), KC_LSFT,  KC_N,   KC_M,    DE_COMM, DE_DOT,   DE_MINS, KC_DEL,
               LT(_ADJUST, KC_LGUI), KC_LCTRL, MT(MOD_LALT, KC_SPC), KC_BSPC, LT(_RAISE, KC_ENTER),    LT(_LOWER, _______), KC_LEFT,  KC_DOWN, KC_UP, KC_RIGHT
    ),
/*
 * Lower Layer: Symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  !   |  "   |  {   |  }   |  |   |                              |      |      |      |      |      |    \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |  $   |  (   |  )   |  `   |                              |   +  |  -   |  /   |  *   |  %   |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  %   |  ^   |  [   |  ]   |  ~   |      |      |  |      |      |   &  |  =   |  ,   |  .   |  ?   | - _    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |  ;   |  =   |  |  =   |  ;   |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_LOWER] = LAYOUT(
      _______, DE_EXLM, DE_DQUO, DE_LCBR, DE_RCBR, DE_PIPE,                                     _______, _______, _______, _______, _______, DE_BSLS,
      _______, DE_QUES, DE_DLR,  DE_LPRN, DE_RPRN, DE_GRV,                                      DE_PLUS, DE_MINS, DE_SLSH, DE_ASTR, DE_PERC, DE_QUOT,
      _______, DE_PERC, DE_CIRC, DE_LBRC, DE_RBRC, DE_TILD, _______, _______, _______, _______, DE_AMPR, DE_EQL,  DE_COMM, DE_DOT,  DE_QUES, DE_MINS,
                                 _______, _______, _______, DE_SCLN, DE_EQL,  DE_EQL,  DE_SCLN, _______, _______, _______
    ),
/*
 * Raise Layer: Number keys, media, navigation
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   1  |  2   |  3   |  4   |  5   |                              |  6   |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      | Prev | Play | Next | VolUp|                              |  F1  | F2   | F3   | F4   | F5   | F6     |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      | Mute | VolDn|      |      |  |      |      |  F7  | F8   | F9   | F10  | F11  | F12    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_RAISE] = LAYOUT(
      _______, KC_1, 	  KC_2,    KC_3,    KC_4,    KC_5,                                      KC_6,  KC_7,  KC_8,    KC_9,   KC_0,   _______,
      _______, _______, KC_MPRV, KC_MPLY, KC_MNXT, KC_VOLU,                                     KC_F1, KC_F2, KC_F3,   KC_F4,  KC_F5,  KC_F6 ,
      _______, _______, _______, _______, KC_MUTE, KC_VOLD, _______, _______, _______, _______, KC_F7, KC_F8, KC_F9,   KC_F10, KC_F11, KC_F12,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
/*
 * Adjust Layer: Function keys, RGB
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | F1   |  F2  | F3   | F4   | F5   |                              | F6   | F7   |  F8  | F9   | F10  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | TOG  | SAI  | HUI  | VAI  | MOD  |                              |      |      |      | F11  | F12  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      | SAD  | HUD  | VAD  | RMOD |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
      _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                     _______, _______, _______, KC_F11,  KC_F12,  _______,
      _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_180;
}

static void render_qwerz(int is_master) {
    if(is_master) {
        oled_write_P(PSTR("|Es|Q|W|E|R|T|      \n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("|Ta|A|S|D|F|G|      \n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("|LS|Y|X|C|V|B|AT|LS|\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("       |G|C| |BS|EN|\n"), false);
        oled_write_P(PSTR("       | | |A|  |Ra|\n"), false);
    } else {
        oled_write_P(PSTR("      |Z|U|I|O|P|+*|\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("      |H|J|K|L| |#'|\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("|LS|LS|N|M|,|.|-|De|\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("|  |LA|D|U|R|       \n"), false);
        oled_write_P(PSTR("|Lo|  | | | |       \n"), false);
    }
}

static void render_lower(int is_master) {
    if(is_master) {
        oled_write_P(PSTR("|  |!|\"|{|}|||     \n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("|  | |$|(|)|`|      \n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("|  |%|^|[|]|~|  |  |\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("       | | | |  |  |\n"), false);
        oled_write_P(PSTR("       | | | |; | =|\n"), false);
    } else {
        oled_write_P(PSTR("      | | | | | |\\ |\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("      |+|-|/|*|%|\"'|\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("|  |  |&|=|,|.|?|-_|\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("|  |  | | | |       \n"), false);
    }
}

static void render_raised(int is_master) {
    if(is_master) {
        oled_write_P(PSTR("| |1|2 |3 |4|5 |    \n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("| | |PR|PL|N|VU|    \n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("| | |  |  |M|VD| | |\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("       |  | |  | | |\n"), false);
        oled_write_P(PSTR("       |  | |  | | |\n"), false);
    } else {
        oled_write_P(PSTR("      |6|7|8|9|0|  |\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("    F|1|2|3|4|5 |6 |\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("   F|7|8|9|10|11|12|\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("  | | | | |  |      \n"), false);
    }
}

static void render_adjust(int is_master) {
    if(is_master) {
        oled_write_P(PSTR("| |F1|F2|F3|F4|F5|  \n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("| |  |  |  |  |  |  \n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("| |  |  |  |  |  |  \n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("                    \n"), false);
        oled_write_P(PSTR("                    \n"), false);
    } else {
        oled_write_P(PSTR("|F6|F7|F8|F9 |F10| |\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("|  |  |  |F11|F12| |\n"), false);
        oled_write_P(PSTR("--------------------\n"), false);
        oled_write_P(PSTR("                    \n"), false);
        oled_write_P(PSTR("                    \n"), false);
        oled_write_P(PSTR("                    \n"), false);
        oled_write_P(PSTR("                    \n"), false);
    }
}

static void render_layout(int is_master) {
    switch (get_highest_layer(layer_state)) {
        case _QWERTZ:
            render_qwerz(is_master);
            break;
        case _LOWER:
            render_lower(is_master);
            break;
        case _RAISE:
            render_raised(is_master);
            break;
        case _ADJUST:
            render_adjust(is_master);
            break;
        default:
            oled_write_P(PSTR("Undefined\n"), false);
    }
}

bool oled_task_user(void) {
    oled_clear();
    if (is_keyboard_master()) {
        render_layout(1);
    } else {
        render_layout(0);
    }
    return false;
}
#endif
