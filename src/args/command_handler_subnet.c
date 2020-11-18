#include "args/command_handler_subnet.h"

#include <stdio.h>

#include "ip4utils.h"
#include "ip4types.h"
#include "ip4io.h"
#include "ip4math.h"
#include "args/process_args.h"

int command_handler_subnet(arg_data_t *pad)
{
    ipv4_addr_t in_addr = scan_ipv4_addr_str(pad->cmdargs[0]);

    ipv4_class_t in_addr_class = ipv4_addr_class(in_addr);

    printf("A cim: "); PRINT_IPV4_ADDR(in_addr, pad->setopts['b']) putchar('\n');

    uint32_t n_subnets;
    sscanf(pad->cmdargs[1], "%u", &n_subnets);

    uint32_t n_bits_to_convert = bits_to_convert(n_subnets);

    uint8_t subn_addr_mask_bits = ipv4_class_default_mask_bits(in_addr_class) + n_bits_to_convert;
    if (subn_addr_mask_bits > 30)
    {
        printf("Hibas adatok! A legnagyobb ervenyes maszk /30-as, a megadott /%d!\n", subn_addr_mask_bits);
        return 1;
    }

    printf("%u alhalozatra kell bontani (%u bit atalakitasaval).\n", pow_u32(2, n_bits_to_convert), n_bits_to_convert);
    
    ipv4_mask_t subn_addr_mask = ipv4_mask_generate(subn_addr_mask_bits);
    printf("Az uj maszk: ");
    PRINT_IPV4_MASK(subn_addr_mask, pad->setopts['b'])
    putchar('\n');
    putchar('\n');

    print_subnets(in_addr, subn_addr_mask, n_subnets, pad->setopts['b']);

    return 0;
}