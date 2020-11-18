#include "args/command_handler_help.h"

#include <stdio.h>

#define USAGE_STR \
    "Hasznalat: ipv4calc [-b] <parancs> [<argumentumok>]\n" \
    "\n" \
    "Parancsok:\n" \
    " subnet <cim> <n>      N darab alhalozatra bont egy halozatot\n" \
    " wildcard <maszk>      Kiszamolja egy maszk wildcard maszkjat\n" \
    " ipinfo <cim> <maszk>  Kiirja a megadott cim osztalyat, alapertelmezett\n" \
    "                       maszkjat, azt, hogy ez milyen cim a megadott maszk\n" \
    "                       alapjan, valamint ha ez nem egy alhalozat cime,\n" \
    "                       akkor az alhalozat cimet is amelyhez tartozik.\n" \
    " help                  Kiirja ezt a menut\n" \
    "\n" \
    "Opciok:\n" \
    " [-b]                  Minden cimet es maszkot binarisan ir ki a program.\n" \
    "\n"

int command_handler_help(arg_data_t *pad)
{
    printf(USAGE_STR);
    return 0;
}
