#include QMK_KEYBOARD_H
#include "mjroghelia.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN] = LAYOUT(
        KC_GESC,          KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_MINS,          KC_EQL,           KC_NO,            KC_BSPC,
        KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_LBRC,          KC_RBRC,          KC_BSLS,
        LT(FN, KC_ESC),   KC_A,             KC_S,             KC_D,             KC_F,             KC_G,             KC_H,             KC_J,             KC_K,             KC_L,             KC_SCLN,          KC_QUOT,          KC_ENT,
        OSM(MOD_LSFT),    KC_NO,            KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,             KC_N,             KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          OSM(MOD_RSFT),    KC_APP,
        KC_LCTL,          KC_LGUI,          KC_LALT,          KC_LCTL,          OSL(FN),          LT(APP, KC_SPC),  OSL(SYM),         KC_LEFT,          KC_DOWN,          KC_UP,            KC_RIGHT
    ),

    [MAC] = LAYOUT(
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_NO,            KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_LGUI,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS
    ),

    [FN] = LAYOUT(
        CK_CLR,           KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_F6,            KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,           KC_F12,           KC_DEL,           KC_NO,
        KC_NO,            CK_QUIT,          CK_FWORD,         CK_EOL,           LCTL(KC_R),       LCTL(KC_GRV),     KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_UP,            KC_NO,            KC_NO,            CK_WIN,
        KC_TRNS,          CK_SOL,           CK_SAVE,          KC_DEL,           KC_RIGHT,         KC_NO,            KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT,          KC_ENT,           KC_GRV,           LCTL(KC_ENT),
        KC_TRNS,          KC_NO,            KC_NO,            CK_CUT,           CK_COPY,          CK_PASTE,         CK_BWORD,         KC_DOWN,          KC_MUTE,          KC_NO,            KC_NO,            CK_MAC,           KC_MPLY,          KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_TRNS,          KC_BSPC,          KC_NO,            KC_MPRV,          KC_VOLD,          KC_VOLU,          KC_MNXT
    ),

    [APP] = LAYOUT(
        CK_CLR,           KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            CK_APP1,          CK_APP2,          CK_APP3,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            CK_NOTN,          CK_APP4,          CK_APP5,          CK_APP6,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO
    ),

    [SYM] = LAYOUT(
        CK_CLR,           S(KC_1),          S(KC_2),          S(KC_3),          S(KC_4),          S(KC_5),          S(KC_6),          S(KC_7),          S(KC_8),          S(KC_9),          S(KC_0),          S(KC_MINS),       S(KC_EQL),        KC_NO,            KC_NO,
        S(KC_EQL),        S(KC_COMM),       KC_EQL,           S(KC_DOT),        KC_MINS,          S(KC_LBRC),       S(KC_RBRC),       S(KC_MINS),       S(KC_BSLS),       S(KC_DOT),        S(KC_5),          S(KC_LBRC),       S(KC_RBRC),       S(KC_BSLS),
        S(KC_GRV),        S(KC_2),          S(KC_4),          S(KC_9),          S(KC_0),          KC_LBRC,          KC_RBRC,          S(KC_7),          S(KC_QUOT),       KC_QUOT,          S(KC_SCLN),       S(KC_QUOT),       KC_NO,
        KC_NO,            KC_BSLS,          S(KC_6),          S(KC_3),          S(KC_1),          KC_GRV,           S(KC_1),          S(KC_8),          S(KC_COMM),       S(KC_DOT),        S(KC_SLSH),       KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_SPC,           KC_NO,            KC_SPC,           KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO
    )
};
