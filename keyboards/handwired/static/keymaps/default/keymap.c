/* Copyright 2019 %YOUR_NAME%
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

// Custom Definitions
#define BL 0
#define FN 1

/*
* Custom Macros
*/
enum custom_keycodes {
    GG_MACRO
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* 0: Default layer
  ┌─────┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │ F1  │ Esc │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │  \  │  `  │
  ├─────├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ F2  │ Tab │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BkSpc│█████│
  ├─────├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ F3  │Ctrl │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │Enter│█████│█████│
  ├─────├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ F4  │Shift│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │Shift│ Fn  │█████│█████│
  ├─────├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ F5  │ Gui │ Alt │Space│ Alt │ Gui │█████│█████│█████│█████│█████│█████│█████│█████│█████│█████│
  └─────└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
    */
  [BL] = LAYOUT(
        KC_F1, KC_ESC,    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS, KC_GRV, \
        KC_F2, KC_TAB,    KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSPC, \
        KC_F3, KC_LCTL,   KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT, \
        KC_F4, KC_LSFT,   KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,  KC_DOT,   KC_SLSH, KC_RSFT, MO(FN), \
        KC_F5, KC_LGUI, KC_LALT,   KC_SPC, KC_RALT, KC_RGUI),

    /* 1: HHKB Fn layer
  ┌─────┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
  │ F6  │     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ Ins │ Del │
  ├─────├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ F7  │Caps │     │     │     │Reset│     │     │     │ Psc │ Slk │ Pus │ Up  │     │     │█████│
  ├─────├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ F8  │     │ VoD │ VoU │ Mut │     │GGWP │NP_* │NP_/ │Home │PgUp │Left │Right│NPEnt│█████│█████│
  ├─────├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ F9  │     │     │     │Calc │     │     │NP_+ │NP_- │ End │PgDwn│Down │     │     │█████│█████│
  ├─────├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
  │ F10 │     │     │     │     │     │█████│█████│█████│█████│█████│█████│█████│█████│█████│█████│
  └─────└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
    */
  [FN]= LAYOUT(
    KC_F6, KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS, KC_DEL,  \
    KC_F7, KC_CAPS,   KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK,KC_PAUS, KC_UP,   KC_TRNS, KC_TRNS, \
    KC_F8, KC_TRNS,   KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, GG_MACRO,KC_PAST, KC_PSLS, KC_HOME, KC_PGUP,KC_LEFT, KC_RGHT, KC_PENT, \
    KC_F9, KC_TRNS,   KC_TRNS, KC_TRNS, KC_CALC, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN,KC_DOWN, KC_TRNS, KC_TRNS, \
    KC_F10, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case GG_MACRO:
          if (record->event.pressed) {
              SEND_STRING(SS_TAP(X_T)"ggwp!"SS_TAP(X_ENTER));
          }
          break;
        default:
          break;
    }
    return true;
}

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
