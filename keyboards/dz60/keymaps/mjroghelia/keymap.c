#include QMK_KEYBOARD_H
#include "mjroghelia.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [MAC] = LAYOUT(
        QK_GESC,          KC_1,             KC_2,             KC_3,             KC_4,             KC_5,             KC_6,             KC_7,             KC_8,             KC_9,             KC_0,             KC_MINS,          KC_EQL,           KC_NO,            KC_BSPC,
        KC_TAB,           KC_Q,             KC_W,             KC_E,             KC_R,             KC_T,             KC_Y,             KC_U,             KC_I,             KC_O,             KC_P,             KC_LBRC,          KC_RBRC,          KC_BSLS,
        LT(NAV, KC_ESC),  KC_A,             KC_S,             KC_D,             KC_F,             KC_G,             KC_H,             KC_J,             KC_K,             KC_L,             KC_SCLN,          KC_QUOT,          KC_ENT,
        OSM(MOD_LSFT),    KC_NO,            KC_Z,             KC_X,             KC_C,             KC_V,             KC_B,             KC_N,             KC_M,             KC_COMM,          KC_DOT,           KC_SLSH,          OSM(MOD_RSFT),    TG(FN),
        KC_LCTL,          KC_LGUI,          KC_LALT,          KC_LGUI,          MO(FN),           LT(SYM, KC_SPC),  KC_RGUI,          KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT
    ),

    [EXTRA] = LAYOUT(
        CK_CLR,           KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_NO,            KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_NO,            KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS
    ),

    [WIN] = LAYOUT(
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_NO,            KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_NO,            KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,
        KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_LCTL,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS,          KC_TRNS
    ),

    [FN] = LAYOUT(
        CK_CLR,           KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_F6,            KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,           KC_F12,           KC_NO,            KC_DEL,
        CK_TAB,           KC_NO,            CK_APP1,          CK_APP2,          CK_APP3,          LCTL(KC_GRV),     KC_NO,            KC_NO,            KC_PGDN,          KC_PGUP,          KC_MPLY,          KC_NO,            KC_NO,            KC_NO,
        KC_NO,            CK_NOTN,          CK_APP4,          CK_APP5,          CK_APP6,          CK_APP7,          KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT,          KC_ENT,           KC_GRV,           KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            CK_APP8,          CK_APP9,          KC_NO,            KC_MUTE,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_TRNS,
        MO(ADMIN),        KC_NO,            KC_NO,            KC_NO,            KC_TRNS,          KC_BSPC,          KC_NO,            KC_MPRV,          KC_VOLD,          KC_VOLU,          KC_MNXT
    ),

    [NAV] = LAYOUT(
        CK_CLR,           KC_F1,            KC_F2,            KC_F3,            KC_F4,            KC_F5,            KC_F6,            KC_F7,            KC_F8,            KC_F9,            KC_F10,           KC_F11,           KC_F12,           KC_NO,            KC_DEL,
        CK_TAB,           KC_NO,            CK_FWORD,         CK_EOL,           LCTL(KC_R),       LCTL(KC_GRV),     KC_NO,            KC_NO,            KC_PGDN,          KC_PGUP,          KC_UP,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            CK_SOL,           CK_SAVE,          KC_DEL,           KC_RGHT,          KC_NO,            KC_LEFT,          KC_DOWN,          KC_UP,            KC_RGHT,          KC_ENT,           KC_GRV,           KC_NO,
        KC_NO,            KC_NO,            LCTL(KC_Z),       LCTL(KC_X),       LCTL(KC_C),       LCTL(KC_V),       KC_LEFT,          KC_DOWN,          KC_MUTE,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_TRNS,
        MO(ADMIN),        KC_NO,            KC_NO,            KC_NO,            KC_TRNS,          KC_BSPC,          KC_NO,            KC_MPRV,          KC_VOLD,          KC_VOLU,          KC_MNXT
    ),

    [SYM] = LAYOUT(
        CK_CLR,           KC_EXLM,          KC_AT,            KC_HASH,          KC_DLR,           KC_PERC,          KC_CIRC,          KC_AMPR,          KC_ASTR,          KC_LPRN,          KC_RPRN,          KC_UNDS,          KC_PLUS,          KC_NO,            KC_NO,
        KC_NO,            KC_ASTR,          KC_PLUS,          KC_MINS,          KC_UNDS,          KC_PIPE,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_TILD,          KC_LT,            KC_EQL,           KC_GT,            KC_LCBR,          KC_RCBR,          KC_NO,            KC_NO,            KC_NO,            KC_TRNS,          KC_DQUO,          KC_NO,
        KC_NO,            KC_NO,            KC_CIRC,          KC_AMPR,          KC_LPRN,          KC_RPRN,          KC_LBRC,          KC_RBRC,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_SPC,           KC_NO,            KC_SPC,           KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO
    ),

    [ADMIN] = LAYOUT(
        CK_CLR,           KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            QK_BOOT,
        KC_NO,            KC_NO,            CK_WIN,           KC_NO,            QK_BOOT,          KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            CK_MAC,           KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,
        KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO,            KC_NO
    )
};
