#!/bin/sh

# ./gen/gen.py pi60
# qmk compile -kb 1upkeyboards/pi60 -km mjroghelia

./gen/gen.py sinc
qmk compile -kb keebio/sinc/rev4 -km mjroghelia
echo ""
echo "Run 'qmk flash -kb keebio/sinc/rev4 -km mjroghelia' and press FN-R"
