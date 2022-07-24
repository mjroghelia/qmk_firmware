#!/usr/bin/env python3

import copy
import json
from pathlib import Path
import sys

def gen_path():
    return Path(__file__).parent

def qmk_path():
    return gen_path().parent

def transform_to_60(layers):
    layers = copy.deepcopy(layers)
    for layer in layers:
        rows = layer['rows']
        del rows[0]
        for i in range(3):
            del rows[i][-1]
        del rows[4][-4]
        del rows[4][-4]
        rows[4].insert(-1, rows[3][-2])
        del rows[3][-2]
        if layer['name'] == 'WIN':
            rows[0][0] = "KC_GESC"
        elif layer['name'] != 'MAC':
            rows[0][0] = "CK_CLR"
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
    
    if target == "dz60_v2" or target == "all":
        render_dz60(layers, True)

    if target ==  "sinc" or target == "all":
        render_sinc(layers)

    if target ==  "quefrency" or target == "all":
        render_quefrency(layers)
    
    if target == "wings" or target == "all":
        render_wings(layers)

if __name__ == '__main__':
    main()
