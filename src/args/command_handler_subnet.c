#include "command_handlers.h"

#include <stdio.h>

#include "ipv4utils.h"
#include "ipv4types.h"
#include "ipv4io.h"
#include "ipv4math.h"
#include "process_args.h"

int command_handler_subnet(arg_data_t *pad)
{
    ipv4_addr_t in_addr;
    
    if(scan_ipv4_addr_str(pad->cmdargs[0], &in_addr) != 4)
    {
        printf("Wrong address format!\n");
        return 1;
    }

    ipv4_class_t in_addr_class = ipv4_addr_class(in_addr);

    printf("The address: "); PRINT_IPV4_ADDR(in_addr, pad->setopts['b']) putchar('\n');

    if (in_addr_class == ip4c_D || in_addr_class == ip4c_E || in_addr_class == ip4c_UD)
    {
        printf("The class of the address: ");
        print_ipv4_class_name(in_addr_class);
        putchar('\n');
        printf("Supply a class A, B or C address!\n");
        return 1;
    }

    uint32_t n_subnets;
    sscanf(pad->cmdargs[1], "%u", &n_subnets);

    uint32_t n_bits_to_convert = bits_to_convert(n_subnets);

    uint8_t subn_addr_mask_bits = ipv4_class_default_mask_bits(in_addr_class) + n_bits_to_convert;
    if (subn_addr_mask_bits > 30)
    {
        printf("The biggesst valid mask is /30, the mask given: /%d!\n", subn_addr_mask_bits);
        return 1;
    }

    printf("Dividing into %u subnets (changing %u bits).\n", pow_u32(2, n_bits_to_convert), n_bits_to_convert);
    
    ipv4_mask_t subn_addr_mask = ipv4_mask_generate(subn_addr_mask_bits);
    printf("The new mask: ");
    PRINT_IPV4_MASK(subn_addr_mask, pad->setopts['b'])
    putchar('\n');
    putchar('\n');

    print_subnets(in_addr, subn_addr_mask, n_subnets, pad->setopts['b']);

    return 0;
}