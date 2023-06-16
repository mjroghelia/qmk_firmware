#!/usr/bin/env python3

import copy
import json
from pathlib import Path
import sys

def gen_path():
    return Path(__file__).parent

def qmk_path():
    return gen_path().parent

def transform_nav(layers):
    layers = copy.deepcopy(layers)
    for layer in layers:
        if layer['name'] == 'NAV':
            nav_rows = layer['rows']
        elif layer['name'] == 'FN':
            fn_rows = layer['rows']
    for i in range(len(nav_rows)):
        row = nav_rows[i]
        for j in range(len(row)):
            if row[j] == 'KC_TRNS':
                row[j] = fn_rows[i][j]
    return layers

def transform_to_65(layers):
    layers = copy.deepcopy(layers)
    for layer in layers:
        rows = layer['rows']
        del rows[0]
        if layer['name'] == 'MAC':
            rows[0][0] = "QK_GESC"
        elif layer['name'] != 'WIN':
            rows[0][0] = "CK_CLR"
    return layers

def transform_to_60(layers):
    layers = transform_to_65(layers)
    for layer in layers:
        rows = layer['rows']
        for i in range(3):
            del rows[i][-1]
        del rows[4][-4]
        del rows[4][-5]
        rows[4].insert(-1, rows[3][-2])
        del rows[3][-2]
    return layers

def render(f, layers, macro):
    print("#include QMK_KEYBOARD_H", file=f)
    print("#include \"mjroghelia.h\"\n", file=f)
    print("const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {\n", file=f)
    for i in range(len(layers)):
        print("    [{}] = {}(".format(layers[i]['name'], macro), file=f)
        rows = layers[i]['rows']
        for j in range(len(rows)):
            row = rows[j]
            print("        ", file=f, end='')
            for k in range(len(row)):
                code = row[k]
                if (k == len(row) - 1):
                    if (j == len(rows) - 1):
                        print("{}".format(code), file=f)
                    else:
                        print("{},".format(code), file=f)
                else:
                    print("{:18}".format(code+','), file=f, end='')
        i_delimiter = '' if (i == len(layers) - 1) else ",\n"
        print("    ){}".format(i_delimiter), file=f)
    print("};", file=f)

# Q11
def render_q11(layers):
    # remove right FN toogle, add right knob, left knob and macros
    layers = copy.deepcopy(layers)
    for layer in layers:
        rows = layer['rows']
        if layer['name'] == 'MAC' or layer['name'] == 'WIN':
            # swap ctrl/gui with fn
            #tmp = rows[5][3]
            #rows[5][3] = rows[5][4]
            #rows[5][4] = tmp
            # left and right knobs
            rows[0].insert(0, "KC_MUTE")
            rows[0].insert(-1, "KC_MUTE")
        else:
            rows[0].insert(0, "KC_NO")
            rows[0].insert(-1, "KC_NO")
        rows[1].insert(0, "KC_NO") # macro
        rows[2].insert(0, "KC_NO") # macro
        rows[3].insert(0, "KC_NO") # macro
        rows[4].insert(0, "KC_NO") # macro
        rows[5].insert(0, "KC_NO") # macro
        del rows[4][-1] # right FN key
    path = qmk_path() / "keyboards" / "keychron" / "q11" / "ansi_encoder" / "keymaps" / "mjroghelia" / "keymap.c"
    with open(path, 'w') as f:
        render(f, layers, 'LAYOUT_ansi_91')
        print("#if defined(ENCODER_MAP_ENABLE)", file=f)
        print("const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {", file=f)
        print("    [MAC] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },", file=f)
        print("    [EXTRA] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },", file=f)
        print("    [WIN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },", file=f)
        print("    [NAV] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },", file=f)
        print("    [FN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },", file=f)
        print("    [ADMIN] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },", file=f)
        print("    [SYM] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },", file=f)
        print("};", file=f)
        print("#endif // ENCODER_MAP_ENABLE", file=f)

# Sinc
def render_sinc(layers):
    layers = copy.deepcopy(layers)
    for layer in layers:
        rows = layer['rows']
        rows[1].insert(-2, "KC_NO") # split backspace
        # extra bottom keys
        rows[5].insert(4, "KC_NO")
        rows[5].insert(6, "KC_NO")
    path = qmk_path() / "keyboards" / "keebio" / "sinc" / "keymaps" / "mjroghelia" / "keymap.c"
    with open(path, 'w') as f:
        render(f, layers, 'LAYOUT_80')


# Keymap template rows indices:
# 0: 0..14
# 1: 0..14
# 2: 0..13
# 3: 0..13
# 4: 0..10

# DZ60
def render_dz60(layers, v2=False):
    layers = transform_to_60(layers)
    for layer in layers:
        rows = layer['rows']
        # split backspace
        rows[0].insert(-1, "KC_NO")
        # extra left iso key
        rows[3].insert(1, "KC_NO")
    model = "dz60"
    if v2:
        model += "_v2"
    path = qmk_path() / "keyboards" / model / "keymaps" / "mjroghelia" / "keymap.c"
    with open(path, 'w') as f:
        render(f, layers, 'LAYOUT')

# YD60MQ
def render_yd60mq(layers):
    layers = transform_to_60(layers)
    for layer in layers:
        rows = layer['rows']
        # split backspace
        rows[0].insert(-1, "KC_DEL")
        # extra right iso key
        rows[2].insert(-1, "KC_NO")
        # extra left iso key
        rows[3].insert(1, "KC_NO")
        # up arrow when using 2u left shift
        rows[3].insert(-2, "KC_NO")
    path = qmk_path() / "keyboards" / "ymdk" / "yd60mq" / "keymaps" / "mjroghelia" / "keymap.c"
    with open(path, 'w') as f:
        render(f, layers, 'LAYOUT_all')

# Quefrency
def render_quefrency(layers):
    layers = transform_to_60(layers)
    for layer in layers:
        rows = layer['rows']
        rows[0].insert(-1, "KC_NO") # split backspace
        rows[4].insert(5, "KC_NO") # extra left key
    path = qmk_path() / "keyboards" / "keebio" / "quefrency" / "keymaps" / "mjroghelia" / "keymap.c"
    with open(path, 'w') as f:
        render(f, layers, 'LAYOUT_60')

# Wings
def render_wings(layers):
    layers = transform_to_65(layers)
    for layer in layers:
        rows = layer['rows']
        del rows[3][-1]
        del rows[4][8]
        del rows[4][6]
        del rows[4][1]
    path = qmk_path() / "keyboards" / "ymdk" / "wingshs" / "keymaps" / "mjroghelia" / "keymap.c"
    with open(path, 'w') as f:
        render(f, layers, 'LAYOUT_all')

# Main
def main():
    with open(gen_path() / 'keymap.json') as keymap_file:
        keymap = json.load(keymap_file)
        layers = transform_nav(keymap['layers'])
        
    target = "q11"

    if (len(sys.argv) >= 2):
        target = sys.argv[1]

    if target == "dz60" or target == "all":
        render_dz60(layers)
    
    if target == "dz60_v2" or target == "all":
        render_dz60(layers, True)

    if target ==  "sinc" or target == "all":
        render_sinc(layers)

    if target ==  "quefrency" or target == "all":
        render_quefrency(layers)
    
    if target ==  "q11" or target == "all":
        render_q11(layers)

    if target == "yd60mq" or target == "all":
        render_yd60mq(layers)

    if target == "wings" or target == "all":
        render_wings(layers)

if __name__ == '__main__':
    main()
