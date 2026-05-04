#!/bin/sh

case "$1" in
  pi60)
    ./gen/gen.py pi60
    qmk compile -kb 1upkeyboards/pi60 -km mjroghelia
    echo ""
    echo "Run 'qmk flash -kb 1upkeyboards/pi60 -km mjroghelia' and press FN-R"
    ;;

  sinc)
    ./gen/gen.py sinc
    qmk compile -kb keebio/sinc/rev4 -km mjroghelia
    echo ""
    echo "Run 'qmk flash -kb keebio/sinc/rev4 -km mjroghelia' and press FN-R"
    ;;

  wings)
    ./gen/gen.py wings
    qmk compile -kb ymdk/wingshs -km mjroghelia
    echo ""
    echo "Run 'qmk flash -kb ymdk/wingshs -km mjroghelia' and press FN-CTRL-R"
    ;;

  ""|-h|--help)
    echo "Usage: $0 {pi60|sinc|wings}"
    ;;

  *)
    echo "Unknown command: $1" >&2
    echo "Run: $0 --help" >&2
    exit 1
    ;;
esac
