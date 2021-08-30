#include "command_handlers.h"

#include <stdio.h>

#define USAGE_STR \
    "Hasznalat: ipv4calc [-b] <command> [<args>]\n" \
    "\n" \
    "Commands:\n" \
    " subnet <addr> <n>     Divides a network to N subnets\n" \
    " wildcard <mask>       Calculates the wildcard mask of the given mask\n" \
    " ipinfo <addr> <mask>  Prints out detailed information on the given ip address and mask\n" \
    " help                  Prints out this menu\n" \
    "\n" \
    "Options:\n" \
    " [-b]                  Prints out all ip addresses and masks in binary format\n" \
    "\n"

int command_handler_help(arg_data_t *pad)
{
    printf(USAGE_STR);
    return 0;
}
