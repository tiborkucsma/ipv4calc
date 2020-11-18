#include "args/command_handler_wildcard.h"

#include <stdio.h>

#include "ip4utils.h"
#include "ip4types.h"
#include "ip4io.h"
#include "ip4math.h"
#include "args/process_args.h"

int command_handler_wildcard(arg_data_t *pad)
{
    ipv4_mask_t in_mask = scan_ipv4_mask_str(pad->cmdargs[0]);

    printf("A maszk:  "); PRINT_IPV4_MASK(in_mask, pad->setopts['b']) putchar('\n');

    printf("Wildcard: "); PRINT_IPV4_MASK(~in_mask, pad->setopts['b']) putchar('\n');

    return 0;
}