#include <stdio.h>
#include <inttypes.h>

#include "ip4utils.h"
#include "ip4types.h"
#include "ip4io.h"
#include "ip4math.h"

int main()
{
    ipv4_addr_t in_addr = scan_ipv4_addr();
    uint32_t n_subnets;
    scanf("%u", &n_subnets);

    uint32_t n_bits_to_convert = bits_to_convert(n_subnets);
    printf("%u alhalozatra kell bontani (%u bit atalakitasaval).\n", pow_u32(2, n_bits_to_convert), n_bits_to_convert);

    ipv4_class_t in_addr_class = ipv4_addr_class(in_addr);
    printf("A cim osztalya: ");
    print_ipv4_class_name(in_addr_class);
    putchar('\n');

    uint8_t subn_addr_mask_bits = ipv4_class_default_mask_bits(in_addr_class) + n_bits_to_convert;
    if (subn_addr_mask_bits > 30)
    {
        printf("Hibas adatok! A legnagyobb ervenyes maszk /30-as, a megadott /%d!\n", subn_addr_mask_bits);
        return 1;
    }
    ipv4_mask_t subn_addr_mask = ipv4_mask_generate(subn_addr_mask_bits);
    printf("Az uj maszk:      ");
    print_ipv4_mask_dec(subn_addr_mask);
    putchar('\n');

    print_subnets(in_addr, subn_addr_mask, n_subnets);
    
    return 0;
}
