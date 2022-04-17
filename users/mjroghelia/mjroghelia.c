#include "mjroghelia.h"

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

	case CK_SOL:
		if (record->event.pressed) {
			if (IS_LAYER_ON(MAC)) {
				SEND_STRING(SS_LCTL("a"));
			}
			else {
				SEND_STRING(SS_TAP(X_HOME));
			}
		}
		return false;

	case CK_EOL:
		if (record->event.pressed) {
			if (IS_LAYER_ON(MAC)) {
				SEND_STRING(SS_LCTL("e"));
			}
			else {
				SEND_STRING(SS_TAP(X_END));
			}
		}
		return false;

	case CK_FWORD:
		if (record->event.pressed) {
			if (IS_LAYER_ON(MAC)) {
				SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)));
			}
			else if (IS_LAYER_ON(WIN)) {
				SEND_STRING(SS_LCTL(SS_TAP(X_RIGHT)));
			}
		}
		return false;

	case CK_BWORD:
		if (record->event.pressed) {
			if (IS_LAYER_ON(MAC)) {
				SEND_STRING(SS_LALT(SS_TAP(X_LEFT)));
			}
			else if (IS_LAYER_ON(WIN)) {
				SEND_STRING(SS_LCTL(SS_TAP(X_LEFT)));
			}
		}
		return false;

	case CK_QUIT:
		if (record->event.pressed) {
			if (IS_LAYER_ON(MAC)) {
				SEND_STRING(SS_LGUI("q"));
			}
			else if (IS_LAYER_ON(WIN)) {
				SEND_STRING(SS_LALT(SS_TAP(X_F4)));
			}
		}
		return false;

	case CK_SAVE:
		if (record->event.pressed) {
			if (IS_LAYER_ON(MAC)) {
				SEND_STRING(SS_LGUI("s"));
			}
			else if (IS_LAYER_ON(WIN)) {
				SEND_STRING(SS_LCTL("s"));
			}
		}
		return false;

	case CK_CUT:
		if (record->event.pressed) {
			if (IS_LAYER_ON(MAC)) {
				SEND_STRING(SS_LGUI("x"));
			}
			else if (IS_LAYER_ON(WIN)) {
				SEND_STRING(SS_LCTL("x"));
			}
		}
		return false;

	case CK_COPY:
		if (record->event.pressed) {
			if (IS_LAYER_ON(MAC)) {
				SEND_STRING(SS_LGUI("c"));
			}
			else if (IS_LAYER_ON(WIN)) {
				SEND_STRING(SS_LCTL("c"));
			}
		}
		return false;

	case CK_PASTE:
		if (record->event.pressed) {
			if (IS_LAYER_ON(MAC)) {
				SEND_STRING(SS_LGUI("v"));
			}
			else if (IS_LAYER_ON(WIN)) {
				SEND_STRING(SS_LCTL("v"));
			}
		}
		return false;

    case CK_APP1:
		return process_app_shortcut(1, record);

    case CK_APP2:
		return process_app_shortcut(2, record);

    case CK_APP3:
		return process_app_shortcut(3, record);

    case CK_APP4:
		return process_app_shortcut(4, record);

    case CK_APP5:
		return process_app_shortcut(5, record);

    case CK_APP6:
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

	case CK_NOTN:
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
