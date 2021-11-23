/* Copyright 2021 Mark Roghelia (@mjroghelia)
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

/*
	Row columns are 15, 15, 14, 13, 9

	[] = LAYOUT_all(
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	),

	[] = LAYOUT_all(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
*/

enum custom_keycodes {
    CK_WEB = SAFE_RANGE,
    CK_MAIL,
    CK_TERM,
    CK_EDIT,
	CK_CHAT,
};

enum layers {
	BASE,
	WIN,
	MAC,
	TEST,
	FN,
	WIN_NAV,
	MAC_NAV,
	WIN_APPS,
	APPS,
	VIM,
	SHELL,
	CODE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT_all(
		KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, TG(FN),
		KC_NO,   KC_A,    KC_S,    KC_D,   KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_GRV,
		KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
		KC_LCTL, KC_LALT, KC_SPC,  MO(FN), KC_SPC,  KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
	),

	[WIN] = LAYOUT_all(
		KC_TRNS,     KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		MO(WIN_NAV), KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, LCTL_T(KC_SPC), KC_TRNS, LT(APPS, KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[MAC] = LAYOUT_all(
		KC_TRNS,     KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		MO(MAC_NAV), KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, LGUI_T(KC_SPC), KC_TRNS, LT(APPS, KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[TEST] = LAYOUT_all(
		KC_TRNS, KC_TRNS,      KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,         KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,      KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,         KC_TRNS, KC_TRNS,         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, LSFT_T(KC_A), LT(WIN_NAV, KC_S), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, LT(CODE, KC_J), LT(SHELL, KC_K), KC_TRNS, RSFT_T(KC_SCLN), KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS,         KC_TRNS, KC_TRNS,         KC_TRNS,
		KC_TRNS, KC_TRNS,      KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[FN] = LAYOUT_all(
		TG(FN), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,    KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,
		KC_NO,  KC_NO,   KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_TRNS,
		KC_NO,  KC_MPRV, KC_MRWD, KC_MFFD, KC_MNXT, KC_MPLY, KC_NO,   KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
		KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  RESET,
		KC_NO,  KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   TO(WIN), TG(TEST), TO(MAC)
	),

	[WIN_NAV] = LAYOUT_all(
		KC_NO,       KC_F1,      KC_F2,          KC_F3,      KC_F4,      KC_F5,         KC_F6,   KC_F7,   KC_F8,          KC_F9,       KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,
		LCA(KC_TAB), KC_NO,      LCTL(KC_RIGHT), KC_END,     KC_NO,      KC_NO,         KC_NO,   KC_NO,   TG(VIM),        LCA(KC_TAB), KC_UP,  KC_NO,  KC_NO,  KC_NO, KC_NO,
		KC_TRNS,     KC_HOME,    LCTL(KC_S),     KC_DEL,     KC_RIGHT,   KC_NO,         KC_LEFT, KC_DOWN, KC_UP,          KC_RGHT,     KC_NO,  KC_NO,  KC_NO,  KC_NO,
		KC_NO,       LCTL(KC_Z), LCTL(KC_X),     LCTL(KC_C), LCTL(KC_V), LCTL(KC_LEFT), KC_DOWN, KC_NO,   LCTL(KC_COMM),  KC_NO,       KC_NO,  KC_NO,  KC_NO,
		KC_NO,       KC_NO,      KC_NO,          KC_NO,      KC_SPC,     KC_NO,         KC_NO,   KC_NO,   KC_NO
	),

	[MAC_NAV] = LAYOUT_all(
		KC_NO,   KC_F1,      KC_F2,          KC_F3,      KC_F4,      KC_F5,         KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,
		KC_NO,   KC_NO,      LALT(KC_RIGHT), LCTL(KC_E), KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_UP,  KC_NO,  KC_NO,  KC_NO, KC_NO,
		KC_TRNS, LCTL(KC_A), KC_NO,          KC_DEL,     KC_RIGHT,   KC_NO,         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,  KC_NO,  KC_NO,  KC_NO,
		KC_NO,   LGUI(KC_Z), LGUI(KC_X),     LGUI(KC_C), LGUI(KC_V), LALT(KC_LEFT), KC_DOWN, KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,
		KC_NO,   KC_NO,      KC_NO,          KC_NO,      KC_SPC,     KC_NO,         KC_NO,   KC_NO,   KC_NO
	),
	
	[WIN_APPS] = LAYOUT_all(
		KC_NO, KC_F1, KC_F2,      KC_F3,      KC_F4, KC_F5,      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,
		KC_NO, KC_NO, LGUI(KC_1), LGUI(KC_4), KC_NO, LGUI(KC_2), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
		KC_NO, KC_NO, LGUI(KC_5), LGUI(KC_3), KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,
		KC_NO, KC_NO, KC_NO,      KC_NO,      KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
		KC_NO, KC_NO, KC_NO,      KC_TRNS,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO
	),

	[APPS] = LAYOUT_all(
		KC_NO, KC_F1, KC_F2,   KC_F3,   KC_F4, KC_F5,   KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,
		KC_NO, KC_NO, CK_WEB,  CK_MAIL, KC_NO, CK_TERM, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
		KC_NO, KC_NO, CK_CHAT, CK_EDIT, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,
		KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
		KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO
	),

	[VIM] = LAYOUT_all(
		TG(VIM), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO
	),

	[SHELL] = LAYOUT_all(
		KC_NO, KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_PERC, KC_CIRC,   KC_AMPR,  KC_PIPE,  KC_LABK, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_HASH, KC_DQUO,   KC_QUOTE, KC_MINUS, KC_RABK, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_DLR,  KC_BSLASH, KC_GRAVE, KC_TILD,  KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO,   KC_NO,     KC_NO,    KC_NO,    KC_NO,   KC_NO, KC_NO, KC_NO
	),

	[CODE] = LAYOUT_all(
		KC_NO, KC_NO,    KC_NO,   KC_NO,       KC_NO,       KC_NO,    KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_EXLM,  KC_AT,   KC_LCBR,     KC_RCBR,     KC_PLUS,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_HASH,  KC_UNDS, KC_LPRN,     KC_RPRN,     KC_EQUAL, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_SLASH, KC_ASTR, KC_LBRACKET, KC_RBRACKET, KC_MINUS, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO,    KC_NO,   KC_NO,       KC_NO,       KC_NO,    KC_NO, KC_NO, KC_NO
	)
};

// Select the app in the dock/taskbar by position
bool process_app_shortcut(int position, keyrecord_t *record) {
	if (position < 1 || position > 5) {
		return true;
	}

	if (record->event.pressed) {
		if (IS_LAYER_ON(MAC)) {
			SEND_STRING(SS_LCTL(SS_TAP(X_F3)) "f");
			for(int i = 0; i < position; i++) {
				SEND_STRING(SS_TAP(X_RIGHT));
			}
			SEND_STRING(SS_TAP(X_ENTER));
		}
		else if (IS_LAYER_ON(WIN)) {
			register_code(KC_LGUI);
			tap_code(KC_1 + (position - 1));
			unregister_code(KC_LGUI);
		}
	}

	return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CK_WEB:
		return process_app_shortcut(1, record);

    case CK_TERM:
		return process_app_shortcut(2, record);

    case CK_EDIT:
		return process_app_shortcut(3, record);

    case CK_MAIL:
		return process_app_shortcut(4, record);

    case CK_CHAT:
		return process_app_shortcut(5, record);

	default:
		return true;
    }
}

void keyboard_post_init_user(void) {
	layer_move(WIN);
}
