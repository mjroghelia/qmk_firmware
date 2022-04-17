import copy
import json
from pathlib import Path

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
        for row in rows:
            del row[-1]
        if layer['name'] == 'WIN':
            rows[3][12] = "KC_DEL"
            rows[4][7]  = "KC_RALT"
            rows[4][8]  = "KC_RCTL"
            rows[4][9] = "MO(FN)"
        elif layer['name'] == 'FN':
            rows[3][12] = "KC_NO"
            rows[4][6]  = "KC_MPRV"
            rows[4][7]  = "KC_VOLD"
            rows[4][8]  = "KC_VOLU"
            rows[4][9] = "KC_MNXT"
    path = qmk_path() / "keyboards" / "dz60" / "keymaps" / "mjroghelia" / "keymap.c"
    with open(path, 'w') as f:
        render(f, layers, 'LAYOUT_60_ansi_split_space_rshift')


# Main
if __name__ == "__main__":

    with open(gen_path() / 'keymap.json') as keymap_file:
        keymap = json.load(keymap_file)
        layers = keymap['layers']

    render_dz60(layers)
