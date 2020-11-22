#include "command_handlers.h"

#include <stdio.h>

#include "ipv4utils.h"
#include "ipv4types.h"
#include "ipv4io.h"
#include "ipv4math.h"
#include "process_args.h"

int command_handler_ipinfo(arg_data_t *pad)
{
    ipv4_addr_t in_addr;
    ipv4_mask_t in_mask;

    if (scan_ipv4_addr_str(pad->cmdargs[0], &in_addr) != 4)
    {
        printf("Hibas formatumban adta meg a cimet!\n");
        return 1;
    }

    printf("A cim:   "); PRINT_IPV4_ADDR(in_addr, pad->setopts['b']) putchar('\n');
    
    if (pad->n_cmdargs == 2)
    {
        if (scan_ipv4_mask_str(pad->cmdargs[1], &in_mask) != 4)
        {
            printf("Hibas formatumban adta meg a maszkot!\n");
            return 1;
        }
        printf("A maszk: "); PRINT_IPV4_MASK(in_mask, pad->setopts['b']) putchar('\n');
    }

    ipv4_class_t in_addr_class = ipv4_addr_class(in_addr);
    printf("A cim osztalya: ");
    print_ipv4_class_name(in_addr_class);
    putchar('\n');
    
    if (in_addr_class == ip4c_A || in_addr_class == ip4c_B || in_addr_class == ip4c_C)
    {
        if (ipv4_addr_private(in_addr)) printf("Privat IP cim\n");
        else printf("Publikus IP cim\n");

        ipv4_mask_t in_addr_mask = ipv4_mask_generate(ipv4_class_default_mask_bits(in_addr_class));
        printf("A cim alapertelmezett maszkja: ");
        PRINT_IPV4_MASK(in_addr_mask, pad->setopts['b'])
        putchar('\n');

        if (pad->n_cmdargs == 2)
        {
            if ((in_addr & in_mask) == in_addr)
            {
                printf("A megadott maszk alapjan ez a cim egy alhalozat cime.\n");
            } else if ((in_addr | ~in_mask) == in_addr)
            {
                printf("A megadott maszk alapjan ez a cim egy alhalozat szorasi cime.\nAz alhalozat cime: ");
                PRINT_IPV4_ADDR(in_addr & in_mask, pad->setopts['b'])
                putchar('\n');
            } else
            {
                printf("A megadott maszk alapjan ez a cim egy host cime.\nAz alhalozat cime: ");
                PRINT_IPV4_ADDR(in_addr & in_mask, pad->setopts['b'])
                putchar('\n');
            }
        }
    }
    return 0;
}