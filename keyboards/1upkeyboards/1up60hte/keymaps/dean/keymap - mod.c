/*
Copyright 2019 Bubnick

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include QMK_KEYBOARD_H

#define BL 0
#define FN 1
#define RGB 2

/*
* Custom Macros
*/
enum custom_keycodes {
    GG_MACRO,
    SPECIAL_MODE
};
bool special_enabled = false;
int special_led = 0;

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	/* 0: Default layer
	┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
	│ Esc │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │  =  │  \  │  `  │
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│ Tab │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │BkSpc│█████│
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│Ctrl │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  '  │█████│Enter│█████│
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│Shift│█████│  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │█████│Shift│ Fn  │
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│█████│ Gui │ Alt │█████│█████│Space│█████│█████│█████│█████│█████│ Alt │ Gui │█████│█████│
	└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
		*/
	[BL] = LAYOUT_all(
        KC_ESC,    KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL, KC_BSLS, \
        KC_TAB,    KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, KC_BSPC,      \
        KC_LCTL,   KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,       KC_ENT,      \
        KC_LSFT,            KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH,      KC_RSFT, MO(FN), \
        KC_TRNS,   KC_LGUI, KC_LALT,              KC_SPC,                         KC_RALT, KC_RGUI, KC_TRNS, KC_GRV),

	  /* 1: HHKB Fn layer
	┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
	│     │ F1  │ F2  │ F3  │ F4  │ F5  │ F6  │ F7  │ F8  │ F9  │ F10 │ F11 │ F12 │ Ins │ Del │
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│Caps │     │     │     │Reset│     │     │     │ Psc │ Slk │ Pus │ Up  │     │     │█████│
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│     │ VoD │ VoU │ Mut │     │GGWP │NP_* │NP_/ │Home │PgUp │Left │Right│█████│NPEnt│█████│
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│     │█████│     │     │Calc │     │     │NP_+ │NP_- │ End │PgDwn│Down │█████│     │     │
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│█████│     │     │█████│█████│█████│     │█████│█████│█████│█████│     │     │█████│█████│
	└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
		*/
	[FN]= LAYOUT_all(
		KC_TRNS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS, \
		KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SLCK, KC_PAUS,   KC_UP, KC_TRNS, KC_TRNS,  \
		KC_TRNS, KC_VOLD, KC_VOLU, KC_MUTE, KC_TRNS, GG_MACRO, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT,       KC_PENT,       \
		KC_TRNS,       KC_TRNS, KC_TRNS, KC_CALC, KC_TRNS, KC_TRNS, KC_PPLS, KC_PMNS,  KC_END, KC_PGDN, KC_DOWN,       KC_TRNS, KC_TRNS, \
		KC_TRNS,   KC_TRNS, KC_TRNS,                   MO(RGB),                         KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL),

	/* 2: HHKB Fn+Shift RGB layer
	┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
	│     │     │     │     │     │     │     │     │     │     │     │     │     │     │     │
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│     │Toggl│Forwa│Rever│     │     │     │     │     │     │     │     │     │     │█████│
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│     │HUI+ │HUI- │Val+ │     │SPMDE│     │     │     │     │     │     │█████│     │█████│
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│     │█████│Sat+ │Sat- │Val- │     │     │     │     │     │     │     │█████│     │     │
	├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
	│█████│     │     │█████│█████│█████│     │█████│█████│█████│█████│     │     │█████│█████│
	└─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
		*/
	[RGB]= LAYOUT_all(
		SPECIAL_MODE,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS, \
		KC_TRNS, RGB_TOG, RGB_MOD, RGB_RMOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS,  \
		KC_TRNS, RGB_HUI, RGB_HUD, RGB_VAI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_TRNS,       KC_TRNS,       \
		KC_TRNS,       RGB_SAI, RGB_SAD, RGB_VAD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,       KC_TRNS, KC_TRNS, \
		KC_TRNS,   KC_TRNS, KC_TRNS,                   KC_TRNS,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

void matrix_init_user(void) {
  setPinOutput(B6);
}

void matrix_scan_user(void) {
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case GG_MACRO:
	        if (record->event.pressed) {
	            SEND_STRING(SS_TAP(X_T)"ggwp!"SS_TAP(X_ENTER));
	        }
	        break;
	    case RGB_MOD:
	    case RGB_RMOD:
	    	// If rgb is changed to a different mode go ahead and shut off our custom mode
	    	special_enabled = false;
	    	break;
	    case SPECIAL_MODE:
	    	special_enabled = !special_enabled;
	    	break;
        default:
        	break;
    }

    // if we're in this mode we will be using a custom rgb layer
    // perform the functions of that layer
    if (special_enabled) {
    	SEND_STRING("g");
    	rgblight_setrgb_at(255,0,0,special_led);
    	if (special_led == RGBLED_NUM) {
    		special_led = 0;
    	} else {
    		special_led++;
    	}
    }
    return true;
}

void led_set_user(uint8_t usb_led) {

	if (usb_led & (1 << USB_LED_NUM_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_CAPS_LOCK)) {
		writePinLow(B6);
	} else {
		writePinHigh(B6);
	}

	if (usb_led & (1 << USB_LED_SCROLL_LOCK)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_COMPOSE)) {

	} else {

	}

	if (usb_led & (1 << USB_LED_KANA)) {

	} else {

	}

}