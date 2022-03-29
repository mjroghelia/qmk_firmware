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

#include "mjroghelia.h"

/*
	To RESET, unplug, hold ESC (top left) and plug in.

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[BASE] = LAYOUT_all(
		KC_GESC, KC_1,    KC_2,    KC_3,   KC_4,   KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,          KC_EQL,  KC_BSPC,   KC_DEL,
		KC_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,          KC_RBRC, KC_BSLS, KC_PGUP,
		KC_ESC,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, LT(SYM, KC_QUOT), KC_ENT,  KC_PGDN,
		KC_LSFT, KC_Z,    KC_X,    KC_C,   KC_V,   KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,
		KC_LCTL, KC_LALT, KC_SPC,  MO(FN), KC_SPC, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
	),

	[WIN] = LAYOUT_all(
		KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		LT(WIN_NAV, KC_ESC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,             KC_TRNS, KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[MAC] = LAYOUT_all(
		KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		LT(MAC_NAV, KC_ESC), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,             KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS,             KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),

	[FN] = LAYOUT_all(
		KC_GRV, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8, KC_F9,    KC_F10, KC_F11, KC_F12, KC_NO,  RESET,
		KC_NO,  KC_NO,   CK_APP1, CK_APP2, CK_APP3, LCTL(KC_GRV), KC_NO,   KC_NO,   KC_NO, KC_NO,    KC_NO,  KC_NO,  KC_NO,  CK_WIN, KC_NO,
		KC_NO,  CK_NOTN, CK_APP4, CK_APP5, CK_APP6, KC_NO,        KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO,  KC_NO,  KC_NO,  KC_MPLY,
		KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,   KC_NO,   KC_NO, KC_NO,    CK_MAC, KC_NO,  KC_VOLU,
		KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_MPRV, KC_VOLD, KC_MNXT
	),

	[SYM] = LAYOUT_all(
		KC_GRV,    S(KC_1),    S(KC_2), S(KC_3),   S(KC_4), S(KC_5),    S(KC_6),    S(KC_7), S(KC_8),    S(KC_9),   S(KC_0),    S(KC_MINS), S(KC_EQL), KC_TRNS, KC_TRNS,
		S(KC_EQL), S(KC_COMM), KC_EQL,  S(KC_DOT), KC_MINS, S(KC_LBRC), S(KC_RBRC), S(KC_7), S(KC_BSLS), S(KC_DOT), S(KC_MINS), KC_NO,      KC_NO,     KC_NO, KC_NO,
		S(KC_8),   S(KC_GRV),  S(KC_4), S(KC_9),   S(KC_0), KC_LBRC,    KC_RBRC,    KC_QUOT, S(KC_SCLN), KC_SCLN,   S(KC_QUOT), KC_TRNS,    KC_NO,     KC_NO,
		KC_NO,     KC_BSLS,    KC_NO,   KC_NO,     KC_NO,   KC_NO,      KC_NO,      KC_NO,   KC_NO,      KC_NO,     KC_NO,      KC_NO,      KC_NO,
		KC_NO,     KC_NO,      KC_NO,   KC_NO,     KC_SPC,  KC_NO,      KC_TRNS,    KC_NO,   KC_NO
	),

	[WIN_NAV] = LAYOUT_all(
		KC_NO,       KC_NO,       KC_NO,          KC_NO,      KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO,         KC_NO,       KC_NO, KC_NO,  KC_NO,        KC_NO, KC_NO,
		LCA(KC_TAB), LALT(KC_F4), LCTL(KC_RIGHT), KC_END,     KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO,         LCA(KC_TAB), KC_UP, KC_NO,  KC_NO,        KC_NO, KC_NO,
		KC_TRNS,     KC_HOME,     LCTL(KC_S),     KC_DEL,     KC_RIGHT,   KC_NO,         KC_LEFT, KC_DOWN, KC_UP,         KC_RGHT,     KC_NO, KC_GRV, LCTL(KC_ENT), KC_NO,
		KC_NO,       LCTL(KC_Z),  LCTL(KC_X),     LCTL(KC_C), LCTL(KC_V), LCTL(KC_LEFT), KC_DOWN, KC_NO,   LCTL(KC_COMM), KC_NO,       KC_NO, KC_NO,  KC_NO,
		KC_NO,       KC_NO,       KC_NO,          KC_NO,      KC_SPC,     KC_NO,         KC_SPC,  KC_NO,   KC_NO
	),

	[MAC_NAV] = LAYOUT_all(
		KC_NO,   KC_NO,      KC_NO,          KC_NO,      KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,  KC_NO,        KC_NO, KC_NO,
		KC_NO,   LGUI(KC_Q), LALT(KC_RIGHT), LCTL(KC_E), KC_NO,      KC_NO,         KC_NO,   KC_NO,   KC_NO, KC_NO,   KC_UP, KC_NO,  KC_NO,        KC_NO, KC_NO,
		KC_TRNS, LCTL(KC_A), KC_NO,          KC_DEL,     KC_RIGHT,   KC_NO,         KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, KC_NO, KC_GRV, LCTL(KC_ENT), KC_NO,
		KC_NO,   LGUI(KC_Z), LGUI(KC_X),     LGUI(KC_C), LGUI(KC_V), LALT(KC_LEFT), KC_DOWN, KC_NO,   KC_NO, KC_NO,   KC_NO, KC_NO,  KC_NO,
		KC_NO,   KC_NO,      KC_NO,          KC_NO,      KC_SPC,     KC_NO,         KC_SPC,  KC_NO,   KC_NO
	)
};
