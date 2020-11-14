#include <stdio.h>
#include <inttypes.h>
#include <unistd.h>
#include <ctype.h>

#include "ip4utils.h"
#include "ip4types.h"
#include "ip4io.h"
#include "ip4math.h"

#define USAGE_STR \
    "Hasznalat: %s [OPCIOK]\n" \
    "\n" \
    "Muveletek csak cimekkel:\n" \
    " -a       IPv4 cim megadasa\n" \
    " [-c]     IPv4 cim osztalyanak kiirasa\n" \
    " [-d]     IPv4 cim alapertelmezett maszkjanak kiirasa\n" \
    " [-s <n>] IPv4 cim felbontasa n alhalozatra es az alhalok kiirasa\n" \
    "\n" \
    "Muveletek csak maszkokkal:\n" \
    " -m       IPv4 maszk megadasa\n" \
    " [-w]     IPv4 maszk atalakitasa wildcardra\n" \
    "\n" \
    "Muveletek cimekkel és maszkokkal: A megadott maszk alapjan mi a cim (alhalozati cim, host cim, szorasi cim)\n" \
    " -a       IPv4 cim megadasa\n" \
    " -m       IPv4 maszk megadasa\n"

int main(int argc, char *argv[])
{
    int   setopts[128] = {};
    char *setoptargs[128] = {};
    int ret;
    while (isalnum(ret = getopt(argc, argv, "a:cds:m:wbh")))
    {
        setopts[ret] = 1;
        setoptargs[ret] = optarg;
    }

    if (setopts['h'])
    {
        printf(USAGE_STR, argv[0]);
        return 0;
    }
    if (ret == '?')
    {
        printf(USAGE_STR, argv[0]);
        return 1;
    }
    if (argc == 1)
    {
        printf("Argumentumok megadasa kotelezo!\n\n");
        printf(USAGE_STR, argv[0]);
        return 1;
    }
    if (!setopts['a'] && !setopts['m'])
    {
        printf("Cim vagy maszk megadasa kotelezo!\n\n");
        printf(USAGE_STR, argv[0]);
        return 1;
    }
    
    if (setopts['a'] && setopts['m'])
    {
        ipv4_addr_t in_addr = scan_ipv4_addr_str(setoptargs['a']);
        ipv4_mask_t in_mask = scan_ipv4_mask_str(setoptargs['m']);

        printf("A cim:   "); PRINT_IPV4_ADDR(in_addr, setopts['b']) putchar('\n');
        printf("A maszk: "); PRINT_IPV4_MASK(in_mask, setopts['b']) putchar('\n');
        
        if ((in_addr & in_mask) == in_addr)
        {
            printf("A megadott maszk alapjan ez a cim egy alhalozat cime.\n");
        } else if ((in_addr | ~in_mask) == in_addr)
        {
            printf("A megadott maszk alapjan ez a cim egy alhalozat szorasi cime.\nAz alhalozat cime: ");
            PRINT_IPV4_ADDR(in_addr & in_mask, setopts['b'])
            putchar('\n');
        } else
        {
            printf("A megadott maszk alapjan ez a cim egy host cime.\nAz alhalozat cime: ");
            PRINT_IPV4_ADDR(in_addr & in_mask, setopts['b'])
            putchar('\n');
        }

    } else if (setopts['a'])
    {
        ipv4_addr_t in_addr = scan_ipv4_addr_str(setoptargs['a']);

        printf("A cim: "); PRINT_IPV4_ADDR(in_addr, setopts['b']) putchar('\n');

        ipv4_class_t in_addr_class = ipv4_addr_class(in_addr);
        if (setopts['c'])
        {
            printf("A cim osztalya: ");
            print_ipv4_class_name(in_addr_class);
            putchar('\n');
        }

        if (setopts['d'])
        {
            ipv4_mask_t in_addr_mask = ipv4_mask_generate(ipv4_class_default_mask_bits(in_addr_class));
            printf("A cim alapertelmezett maszkja: ");

            PRINT_IPV4_MASK(in_addr_mask, setopts['b'])

            putchar('\n');
        }

        if (setopts['s'])
        {
            uint32_t n_subnets;
            sscanf(setoptargs['s'], "%u", &n_subnets);

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
            PRINT_IPV4_MASK(subn_addr_mask, setopts['b'])
            putchar('\n');
            putchar('\n');

            print_subnets(in_addr, subn_addr_mask, n_subnets, setopts['b']);
        }
    } else if (setopts['m'])
    {
        ipv4_mask_t in_mask = scan_ipv4_mask_str(setoptargs['m']);

        printf("A maszk:  "); PRINT_IPV4_MASK(in_mask, setopts['b']) putchar('\n');

        if (setopts['w'])
        {
            printf("Wildcard: "); PRINT_IPV4_MASK(~in_mask, setopts['b']) putchar('\n');
        }
    }
    
    return 0;
}
