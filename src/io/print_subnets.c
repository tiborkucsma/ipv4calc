#include "ipv4io.h"

#include "ipv4types.h"
#include "ipv4math.h"
#include "ipv4utils.h"

#include <stdio.h>
#include <inttypes.h>

void print_subnets(ipv4_addr_t addr, ipv4_mask_t subn_mask, uint32_t n_subnets, int binary_out)
{
    uint8_t orig_mask_bits = ipv4_class_default_mask_bits(ipv4_addr_class(addr));
    ipv4_mask_t orig_mask = ipv4_mask_generate(orig_mask_bits);

    uint8_t subn_mask_bits = ipv4_mask_bits(subn_mask);

    addr = addr & orig_mask;

    for (uint32_t i = 0; i < n_subnets; i++)
    {
        ipv4_addr_t subnet_addr;
        subnet_addr = addr | (i << (32 - subn_mask_bits));
        printf("%u. alhalozat:\n", i + 1);
        printf("Alhalozat cime:            "); PRINT_IPV4_ADDR(subnet_addr,                    binary_out); putchar('\n');
        printf("Elso kioszthato cim:       "); PRINT_IPV4_ADDR(subnet_addr + 1,                binary_out); putchar('\n');
        printf("Utolso kioszthato cim:     "); PRINT_IPV4_ADDR((subnet_addr | ~subn_mask) - 1, binary_out); putchar('\n');
        printf("Broadcast cim:             "); PRINT_IPV4_ADDR(subnet_addr | ~subn_mask,       binary_out); putchar('\n');
        printf("Lehetseges eszkozok szama: %d", (subnet_addr | ~subn_mask) - (subnet_addr + 1));            putchar('\n');
        putchar('\n');
    }
}
