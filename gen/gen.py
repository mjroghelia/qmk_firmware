#!/usr/bin/env python3

import copy
import json
from pathlib import Path
import sys

def gen_path():
    return Path(__file__).parent

def qmk_path():
    return gen_path().parent

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

# Keymap template rows indices:
# 0: 0..14
# 1: 0..14
# 2: 0..13
# 3: 0..13
# 4: 0..10

# DZ60
def render_dz60(layers):
    layers = copy.deepcopy(layers)
    for layer in layers:
        rows = layer['rows']
        del rows[1][-1]
        del rows[2][-1]
        del rows[3][-1]
        if layer['name'] == 'WIN':
            rows[0][-1] = "KC_BSPC"
            rows[0][-2] = "KC_NO"
            rows[3].insert(1, "KC_NO")
            rows[3][-1] = "KC_APP"
            rows[4][-5]  = "OSL(SYM)"
            rows[4][-4]  = "KC_LEFT"
            rows[4][-3]  = "KC_DOWN"
            rows[4][-2]  = "KC_UP"
            rows[4][-1] = "KC_RIGHT"
        elif layer['name'] == 'FN':
            rows[3].insert(0, "KC_TRNS")
            rows[3][-1] = "KC_NO"
            rows[4][-4]  = "KC_MPRV"
            rows[4][-3]  = "KC_VOLD"
            rows[4][-2]  = "KC_VOLU"
            rows[4][-1] = "KC_MNXT"
        else:
            rows[4].insert(0, "KC_NO")

    path = qmk_path() / "keyboards" / "dz60" / "keymaps" / "mjroghelia" / "keymap.c"
    with open(path, 'w') as f:
        render(f, layers, 'LAYOUT')

# Quefrency
def render_quefrency(layers):
    layers = copy.deepcopy(layers)
    for layer in layers:
        rows = layer['rows']
        # unused positions
        rows[0].insert(13, 'KC_NO')
        rows[4].insert(5, 'KC_NO')
        rows[4].insert(9, 'KC_NO')
        # swap the poorly positioned fn :(
        old = rows[4][3]
        rows[4][3] = rows[4][4]
        rows[4][4] = old
    path = qmk_path() / "keyboards" / "keebio" / "quefrency" / "keymaps" / "mjroghelia" / "keymap.c"
    with open(path, 'w') as f:
        render(f, layers, 'LAYOUT_65')

# Wings
def render_wings(layers):
    layers = copy.deepcopy(layers)
    for layer in layers:
        rows = layer['rows']
        del rows[3][-1]
        del rows[4][1]
        del rows[4][6]
    path = qmk_path() / "keyboards" / "ymdk" / "wingshs" / "keymaps" / "mjroghelia" / "keymap.c"
    with open(path, 'w') as f:
        render(f, layers, 'LAYOUT_all')

# Main
def main():
    with open(gen_path() / 'keymap.json') as keymap_file:
        keymap = json.load(keymap_file)
        layers = keymap['layers']
    
    target = "all"

    if (len(sys.argv) >= 2):
        target = sys.argv[1]

    if target == "dz60" or target == "all":
        render_dz60(layers)
    
    if target ==  "quefrency" or target == "all":
        render_quefrency(layers)
    
    if target == "wings" or target == "all":
        render_wings(layers)

if __name__ == '__main__':
    main()
