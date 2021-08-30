#include "command_handlers.h"

#include <stdio.h>

#include "ipv4utils.h"
#include "ipv4types.h"
#include "ipv4io.h"
#include "ipv4math.h"
#include "process_args.h"

int command_handler_wildcard(arg_data_t *pad)
{
    ipv4_mask_t in_mask;
    
    if (scan_ipv4_mask_str(pad->cmdargs[0], &in_mask) != 4)
    {
        printf("Wrong mask format!\n");
        return 1;
    }

    printf("The mask: "); PRINT_IPV4_MASK(in_mask, pad->setopts['b']) putchar('\n');

    printf("Wildcard: "); PRINT_IPV4_MASK(~in_mask, pad->setopts['b']) putchar('\n');

    return 0;
}