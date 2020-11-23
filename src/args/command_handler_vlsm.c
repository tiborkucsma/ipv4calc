#include "command_handlers.h"

#include <stdio.h>
#include <stdlib.h>

#include "ipv4utils.h"
#include "ipv4types.h"
#include "ipv4io.h"
#include "ipv4math.h"
#include "process_args.h"

int command_handler_vlsm(arg_data_t *pad)
{
    ipv4_addr_t in_addr;
    
    if(scan_ipv4_addr_str(pad->cmdargs[0], &in_addr) != 4)
    {
        printf("Hibas formatumban adta meg a cimet!\n");
        return 1;
    }

    ipv4_class_t in_addr_class = ipv4_addr_class(in_addr);

    if (in_addr_class == ip4c_D || in_addr_class == ip4c_E || in_addr_class == ip4c_UD)
    {
        printf("A cim osztalya: ");
        print_ipv4_class_name(in_addr_class);
        putchar('\n');
        printf("Adjon meg A, B vagy C osztalyos cimet!\n");
        return 1;
    }

    uint32_t needed_hosts = 0;
    for (int i = 1; i < pad->n_cmdargs; i++)
    {
        uint32_t hosts = strtoul(pad->cmdargs[i], NULL, 10) + 2;
        uint32_t j;
        for (j = 1; j < hosts; j *= 2);
        needed_hosts += j;
    }
    if (needed_hosts > pow_u32(2, 32 - ipv4_class_default_mask_bits(in_addr_class)))
    {
        printf("Tul sok hoszt cim szukseges, nem lehet igy felosztani!\n");
        return 1;
    }

    subnet_list_create_info_t subnet_info;
    subnet_info.st_addr = in_addr;
    subnet_info.st_mask = ipv4_mask_generate(ipv4_class_default_mask_bits(in_addr_class));
    subnet_info.n_subnets = 0;
    subnet_info.n_subnets_to_include = 1;
    for (int i = 1; i < pad->n_cmdargs; i++)
    {
        subnet_info.n_hosts = strtoul(pad->cmdargs[i], NULL, 10);
        
        subnet_list_t subnet_list;
        int res = ipv4_subnet(&subnet_list, &subnet_info);
        if (res > 0)
        {
            if (res > 1) printf("A legnagyobb ervenyes maszk /30-as, a megadott /%d!\n", res);
            return 1;
        }

        printf("%u. alhalozat:\n", i);
        printf("Maszk:\t\t\t");
        PRINT_IPV4_MASK(subnet_list.data[0].mask, pad->setopts['b']) putchar('\n');
        print_subnet(subnet_list.data[0], pad->setopts['b']);

        subnet_info.st_mask = subnet_list.data[0].mask;
        subnet_info.st_addr = (subnet_list.data[0].addr | ~subnet_info.st_mask) + 1;

        ipv4_destroy_subnet_list(&subnet_list);
    }
    
    return 0;
}