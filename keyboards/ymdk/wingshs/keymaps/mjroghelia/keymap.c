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

// Row columns are 15, 15, 14, 13, 9

enum layers {
    WIN_BASE,
    WIN_NAV,
	WIN_APPS,
    MAC_BASE,
    MAC_NAV,
	MEDIA_ETC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[WIN_BASE] = LAYOUT_all(
		KC_GESC,     KC_1,    KC_2,    KC_3,         KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,      KC_DEL,
		KC_TAB,      KC_Q,    KC_W,    KC_E,         KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,      KC_GRV,
		MO(WIN_NAV), KC_A,    KC_S,    KC_D,         KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  TG(MEDIA_ETC),
		KC_LSFT,     KC_Z,    KC_X,    KC_C,         KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
		KC_LCTL,     KC_LALT, KC_LCTL, MO(WIN_APPS), KC_SPC,  KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
	),

	[WIN_NAV] = LAYOUT_all(
		KC_GRV,        KC_F1,      KC_F2,          KC_F3,      KC_F4,      KC_F5,         KC_F6,   KC_F7,   KC_F8,          KC_F9,   KC_F10, KC_F11, KC_F12, KC_NO, RESET,
		LCA(KC_TAB),   KC_NO,      LCTL(KC_RIGHT), KC_END,     KC_NO,      KC_NO,         KC_NO,   KC_NO,   LCA(KC_TAB),    KC_NO,   KC_UP,  KC_NO,  KC_NO,  KC_NO, KC_NO,
		KC_TRNS,       KC_HOME,    LCTL(KC_S),     KC_DEL,     KC_RIGHT,   KC_NO,         KC_LEFT, KC_DOWN, KC_UP,          KC_RGHT, KC_NO,  KC_NO,  KC_NO,  KC_NO,
		KC_NO,         LCTL(KC_Z), LCTL(KC_X),     LCTL(KC_C), LCTL(KC_V), LCTL(KC_LEFT), KC_DOWN, KC_NO,   LCTL(KC_COMM),  KC_NO,   KC_NO,  KC_NO,  KC_NO,
		KC_NO,         KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO
	),

	[WIN_APPS] = LAYOUT_all(
		KC_NO, KC_F1, KC_F2,      KC_F3,      KC_F4, KC_F5,      KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO, KC_NO,
		KC_NO, KC_NO, LGUI(KC_1), LGUI(KC_4), KC_NO, LGUI(KC_2), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,
		KC_NO, KC_NO, LGUI(KC_5), LGUI(KC_3), KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,
		KC_NO, KC_NO, KC_NO,      KC_NO,      KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,
		KC_NO, KC_NO, KC_NO,      KC_TRNS,    KC_NO, KC_NO,      KC_NO, KC_NO, KC_NO
	),

	[MAC_BASE] = LAYOUT_all(
		KC_GESC,     KC_1,    KC_2,    KC_3,        KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_DEL,
		KC_TAB,      KC_Q,    KC_W,    KC_E,        KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
		MO(MAC_NAV), KC_A,    KC_S,    KC_D,        KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,  TG(MEDIA_ETC),
		KC_LSFT,     KC_Z,    KC_X,    KC_C,        KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP,
		KC_LCTL,     KC_LGUI, KC_LGUI, MO(MAC_NAV), KC_SPC, KC_RALT, KC_LEFT, KC_DOWN, KC_RGHT
	),
	
	[MAC_NAV] = LAYOUT_all(
		KC_GRV,  KC_F1,      KC_F2,          KC_F3,      KC_F4,      KC_F5,         KC_F6,   KC_F7,   KC_F8, KC_F9,   KC_F10, KC_F11, KC_F12, KC_NO, RESET,
		KC_NO,   KC_NO,      LALT(KC_RIGHT), LCTL(KC_E), KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_UP,  KC_NO,  KC_NO,  KC_NO, KC_NO,
		KC_TRNS, LCTL(KC_A), KC_NO,          KC_DEL,     KC_RIGHT,   KC_NO,         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO,  KC_NO,  KC_NO,  KC_NO,
		KC_NO,   LGUI(KC_Z), LGUI(KC_X),     LGUI(KC_C), LGUI(KC_V), LALT(KC_LEFT), KC_DOWN, KC_NO,   KC_NO, KC_NO,   KC_NO,  KC_NO,  KC_NO,
		KC_NO,   KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO
	),
	
	[MEDIA_ETC] = LAYOUT_all(
		KC_NO, DF(0), DF(3),   KC_NO,   KC_NO,   KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
		KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,    KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,   KC_NO,
		KC_NO, KC_NO, KC_MPLY, KC_MRWD, KC_MFFD, KC_NO, KC_NO,    KC_VOLD, KC_VOLU, KC_NO, KC_NO, KC_NO, KC_NO, KC_TRNS,
		KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,    KC_MUTE, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO,
		KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO, RGB_RMOD, RGB_TOG, RGB_MOD
	)
};
