#include QMK_KEYBOARD_H
#include "mjroghelia.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN] = LAYOUT_all(
        KC_GRV,           KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_MINS,          KC_EQL,           KC_DEL,           KC_BSPC,
        KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_LBRC,          KC_RBRC,          KC_BSLS,
        LT(NAV, KC_ESC),  KC_A,             KC_S,             KC_D,             KC_F,             KC_G,             KC_H,             KC_J,             KC_K,             KC_L,             KC_SCLN,          KC_QUOT,          KC_NO,            KC_ENT,
        OSM(MOD_LSFT),    KC_NO,            KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,             KC_N,             KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          KC_NO,            OSM(MOD_RSFT),    MO(ADMIN),
        KC_LCTL,          KC_LGUI,          KC_LALT,          KC_LCTL,          MO(FN),           LT(SYM, KC_SPC),  KC_RGUI,          KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT
    ),

    [MAC] = LAYOUT_all(
        KC_GRV,           KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_MINS,          KC_EQL,           KC_DEL,           KC_BSPC,
        KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_LBRC,          KC_RBRC,          KC_BSLS,
        LT(NAV, KC_ESC),  KC_A,             KC_S,             KC_D,             KC_F,             KC_G,             KC_H,             KC_J,             KC_K,             KC_L,             KC_SCLN,          KC_QUOT,          KC_NO,            KC_ENT,
        OSM(MOD_LSFT),    KC_NO,            KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,             KC_N,             KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          KC_NO,            OSM(MOD_RSFT),    MO(ADMIN),
        KC_LCTL,          KC_LGUI,          KC_LALT,          KC_LGUI,          MO(FN),           LT(SYM, KC_SPC),  KC_RGUI,          KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT
    ),

    [FN] = LAYOUT_all(
        KC_NO,            KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_F6,            KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,           KC_F12,           KC_DEL,           KC_DEL,
        CK_TAB,           KC_NO,            CK_APP1,          CK_APP2,          CK_APP3,          KC_NO,            KC_NO,            KC_NO,            KC_PGDN,          KC_PGUP,          KC_MPLY,          KC_NO,            KC_NO,            KC_NO,
        CK_CLR,           CK_NOTN,          CK_APP4,          CK_APP5,          CK_APP6,          CK_APP7,          KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT,          KC_ENT,           KC_GRV,           KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_MUTE,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_TRNS,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_TRNS,          KC_BSPC,          KC_NO,            KC_MPRV,          KC_VOLD,          KC_VOLU,          KC_MNXT
    ),

    [NAV] = LAYOUT_all(
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_DEL,           KC_NO,
        KC_NO,            KC_NO,            CK_FWORD,         CK_EOL,           LCTL(KC_R),       KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_UP,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            CK_SOL,           CK_SAVE,          KC_DEL,           KC_RGHT,          KC_NO,            KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT,          KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_LSFT,          KC_NO,            LCTL(KC_Z),       LCTL(KC_X),       LCTL(KC_C),       LCTL(KC_V),       CK_BWORD,         KC_DOWN,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_RSFT,          KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO
    ),

    [SYM] = LAYOUT_all(
        KC_TILD,          KC_EXLM,          KC_AT,            KC_HASH,          KC_DLR,           KC_PERC,          KC_CIRC,          KC_AMPR,          KC_ASTR,          KC_LPRN,          KC_RPRN,          KC_UNDS,          KC_PLUS,          KC_DEL,           KC_BSPC,
        KC_NO,            KC_TILD,          KC_PLUS,          KC_MINS,          KC_UNDS,          KC_LCBR,          KC_CIRC,          KC_ASTR,          KC_LPRN,          KC_RPRN,          KC_DQUO,          KC_NO,            KC_NO,            KC_NO,
        CK_CLR,           KC_EXLM,          KC_LT,            KC_EQL,           KC_GT,            KC_RCBR,          KC_NO,            KC_PIPE,          KC_AMPR,          KC_DQUO,          KC_TRNS,          KC_DQUO,          KC_NO,            KC_ENT,
        KC_LSFT,          KC_NO,            KC_BSLS,          KC_PERC,          KC_ASTR,          KC_LBRC,          KC_RBRC,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_RSFT,          KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_SPC,           KC_SPC,           KC_SPC,           KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO
    ),

    [NUM] = LAYOUT_all(
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_DEL,           KC_NO,
        KC_NO,            KC_NO,            KC_1,             KC_2,             KC_3,             KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        CK_CLR,           KC_NO,            KC_4,             KC_5,             KC_6,             KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_7,             KC_8,             KC_9,             KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_0,             KC_0,             KC_0,             KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO
    ),

    [ADMIN] = LAYOUT_all(
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_DEL,           QK_BOOT,
        KC_NO,            KC_NO,            CK_WIN,           KC_NO,            QK_BOOT,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        CK_CLR,           KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            CK_MAC,           KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO
    )
};
