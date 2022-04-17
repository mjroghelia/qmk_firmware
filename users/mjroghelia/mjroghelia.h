#ifndef USERSPACE
#define USERSPACE

#include "quantum.h"

// options for user config
enum config_opts {
	WINDOWS_MODE = 1,
	MAC_MODE = 2,
};

enum custom_keycodes {
	CK_WIN = SAFE_RANGE,
	CK_MAC,
	CK_SOL,
	CK_EOL,
	CK_FWORD,
	CK_BWORD,
	CK_QUIT,
	CK_SAVE,
	CK_CUT,
	CK_COPY,
	CK_PASTE,
	CK_NOTN,
	CK_APP1,
	CK_APP2,
	CK_APP3,
	CK_APP4,
	CK_APP5,
	CK_APP6
};

enum layers {
	BASE,
	WIN,
	MAC,
	FN,
	ADMIN,
	APP,
	SYM
};

#endif
