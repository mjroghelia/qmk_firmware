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
	Row columns are 16, 15, 14, 14, 13

	[] = LAYOUT_65(
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	),

	[] = LAYOUT_65(
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
*/

// options for user config
enum config_opts {
	WINDOWS_MODE = 1,
	MAC_MODE = 2,
};

enum custom_keycodes {
	CK_WEB = SAFE_RANGE,
	CK_MAIL,
	CK_TERM,
	CK_EDIT,
	CK_CHAT,
	CK_WIN,
	CK_MAC,
	CK_ALERTS,
	CK_CAL
};

enum layers {
	BASE,
	WIN,
	MAC,
	FN,
	ADMIN,
	WIN_NAV,
	MAC_NAV,
	APPS,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT_65(
		KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC,   KC_DEL,
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, TG(FN),
		KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  TG(FN),
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   TG(ADMIN),
		KC_LCTL, MO(FN),  KC_LGUI, KC_LALT, KC_SPC,  KC_NO,   KC_SPC,  KC_RGUI, KC_RCTL, KC_NO,   KC_LEFT, KC_DOWN, KC_RGHT
	),

	[WIN] = LAYOUT_65(
		KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		MO(WIN_NAV), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, LCTL_T(KC_SPC), KC_TRNS, LT(APPS, KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[MAC] = LAYOUT_65(
		KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		MO(MAC_NAV), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, LGUI_T(KC_SPC), KC_TRNS, LT(APPS, KC_SPC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[FN] = LAYOUT_65(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11, KC_F12, KC_NO, KC_NO, KC_NO,
		KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_MPLY, KC_NO,  KC_NO,  KC_NO, KC_TRNS,
		KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_NO,   KC_NO,  KC_NO,  KC_TRNS,
		KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,  KC_TRNS,
		KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO
	),

	[ADMIN] = LAYOUT_65(
		TG(ADMIN), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_TRNS,
		KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, KC_NO, KC_TRNS,
		KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO, RESET, KC_TRNS,
		KC_NO,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, CK_WIN, KC_NO, CK_MAC
	),

	[WIN_NAV] = LAYOUT_65(
		KC_NO,       KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO,         KC_NO,       KC_NO, KC_NO,  KC_NO,        KC_NO, KC_NO, KC_NO,
		LCA(KC_TAB), KC_NO,      LCTL(KC_RIGHT), KC_END,     KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO,         LCA(KC_TAB), KC_UP, KC_NO,  KC_NO,        KC_NO, KC_NO,
		KC_TRNS,     KC_HOME,    LCTL(KC_S),     KC_DEL,     KC_RIGHT,   KC_NO,         KC_LEFT, KC_DOWN, KC_UP,         KC_RGHT,     KC_NO, KC_GRV, LCTL(KC_ENT), KC_NO,
		KC_NO,       LCTL(KC_Z), LCTL(KC_X),     LCTL(KC_C), LCTL(KC_V), LCTL(KC_LEFT), KC_DOWN, KC_NO,   LCTL(KC_COMM), KC_NO,       KC_NO, KC_NO,  KC_NO,        KC_NO,
		KC_NO,       KC_NO,      KC_NO,          KC_NO,      KC_SPC,     KC_NO,         KC_SPC,  KC_NO,   KC_NO,         KC_NO,       KC_NO, KC_NO,  KC_NO
	),

	[MAC_NAV] = LAYOUT_65(
		KC_NO,   KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,  KC_NO,        KC_NO, KC_NO, KC_NO,
		KC_NO,   KC_NO,      LALT(KC_RIGHT), LCTL(KC_E), KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_UP, KC_NO,  KC_NO,        KC_NO, KC_NO,
		KC_TRNS, LCTL(KC_A), KC_NO,          KC_DEL,     KC_RIGHT,   KC_NO,         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_GRV, LCTL(KC_ENT), KC_NO,
		KC_NO,   LGUI(KC_Z), LGUI(KC_X),     LGUI(KC_C), LGUI(KC_V), LALT(KC_LEFT), KC_DOWN, KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,  KC_NO,        KC_NO,
		KC_NO,   KC_NO,      KC_NO,          KC_NO,      KC_SPC,     KC_NO,         KC_SPC,  KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,  KC_NO
	),
	
	[APPS] = LAYOUT_65(
		KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO,     CK_WEB,  CK_MAIL, KC_NO, CK_TERM, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, CK_ALERTS, CK_CHAT, CK_EDIT, KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO,     KC_NO,   CK_CAL,  KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO,     KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
	)
};

bool in_app_shortcut = false;

// Select the app in the dock/taskbar by position
bool process_app_shortcut(int position, keyrecord_t *record) {
	if (position < 1 || position > 6) {
		return true;
	}

	if (IS_LAYER_ON(MAC)) {
		if (record->event.pressed) {
			SEND_STRING(SS_LCTL(SS_TAP(X_F3)) "f");
			for(int i = 0; i < position; i++) {
				SEND_STRING(SS_TAP(X_RIGHT));
			}
			SEND_STRING(SS_TAP(X_ENTER));
		}
	}
	else if (IS_LAYER_ON(WIN)) {
		if (record->event.pressed) {
			in_app_shortcut = true;
			register_code(KC_LGUI);
			tap_code_delay(KC_1 + (position - 1), 100);
		}
	}

	return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
	if (in_app_shortcut) {
		unregister_code(KC_LGUI);
		in_app_shortcut = false;
	}
  	return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
	
    case CK_WEB:
		return process_app_shortcut(1, record);

    case CK_TERM:
		return process_app_shortcut(2, record);

    case CK_EDIT:
		return process_app_shortcut(3, record);

    case CK_CHAT:
		return process_app_shortcut(4, record);

    case CK_MAIL:
		return process_app_shortcut(5, record);

    case CK_CAL:
		return process_app_shortcut(6, record);

	case CK_WIN:
		if (record->event.pressed) {
			eeconfig_update_user(WINDOWS_MODE);
			layer_move(WIN);
		}
        return false;

	case CK_MAC:
		if (record->event.pressed) {
			eeconfig_update_user(MAC_MODE);
			layer_move(MAC);
		}
        return false;

	case CK_ALERTS:
		if (record->event.pressed) {
			if (IS_LAYER_ON(MAC)) {
				SEND_STRING(SS_LSFT(SS_LGUI("o")));
			}
			else if (IS_LAYER_ON(WIN)) {
				SEND_STRING(SS_LGUI("n"));
			}
		}
		return false;

	default:
		return true;
    }
}

void keyboard_post_init_user(void) {
	uint32_t conf = eeconfig_read_user();

	if (conf == WINDOWS_MODE) {
		layer_move(WIN);
	}
	else if (conf == MAC_MODE) {
		layer_move(MAC);
	}
}
