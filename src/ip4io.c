#include "ip4io.h"

#include "ip4types.h"
#include "ip4math.h"
#include "ip4utils.h"

#include <stdio.h>
#include <inttypes.h>

void print_byte_bin(uint8_t byte)
{
    for (int8_t i = 7; i >= 0; --i)
    {
        printf("%u", byte >> i & 1);
    }
}

void print_ipv4_addr_bin(ipv4_addr_t addr)
{
    print_byte_bin(ipv4_addr_octet(addr, 0));
    putchar(' ');
    print_byte_bin(ipv4_addr_octet(addr, 1));
    putchar(' ');
    print_byte_bin(ipv4_addr_octet(addr, 2));
    putchar(' ');
    print_byte_bin(ipv4_addr_octet(addr, 3));
}

void print_ipv4_mask_bin(ipv4_mask_t mask)
{
    print_byte_bin(ipv4_mask_octet(mask, 0));
    putchar(' ');
    print_byte_bin(ipv4_mask_octet(mask, 1));
    putchar(' ');
    print_byte_bin(ipv4_mask_octet(mask, 2));
    putchar(' ');
    print_byte_bin(ipv4_mask_octet(mask, 3));
}

void print_ipv4_addr_dec(ipv4_addr_t addr)
{
    printf("%hhu.%hhu.%hhu.%hhu",
        ipv4_addr_octet(addr, 0),
        ipv4_addr_octet(addr, 1),
        ipv4_addr_octet(addr, 2),
        ipv4_addr_octet(addr, 3));
}

void print_ipv4_mask_dec(ipv4_mask_t mask)
{
    printf("%hhu.%hhu.%hhu.%hhu",
        ipv4_mask_octet(mask, 0),
        ipv4_mask_octet(mask, 1),
        ipv4_mask_octet(mask, 2),
        ipv4_mask_octet(mask, 3));
}

ipv4_addr_t scan_ipv4_addr()
{
    ipv4_addr_t res = 0;
    uint8_t a, b, c, d;
    scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
    res |= a << 24;
    res |= b << 16;
    res |= c << 8;
    res |= d << 0;
    return res;
}

ipv4_mask_t scan_ipv4_mask()
{
    ipv4_mask_t res = 0;
    uint8_t a, b, c, d;
    scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
    res |= a << 24;
    res |= b << 16;
    res |= c << 8;
    res |= d << 0;
    return res;
}

ipv4_addr_t scan_ipv4_addr_str(const char *str)
{
    ipv4_addr_t res = 0;
    uint8_t a, b, c, d;
    sscanf(str, "%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
    res |= a << 24;
    res |= b << 16;
    res |= c << 8;
    res |= d << 0;
    return res;
}

ipv4_mask_t scan_ipv4_mask_str(const char *str)
{
    ipv4_mask_t res = 0;
    uint8_t a, b, c, d;
    sscanf(str, "%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
    res |= a << 24;
    res |= b << 16;
    res |= c << 8;
    res |= d << 0;
    return res;
}

void print_ipv4_class_name(ipv4_class_t class)
{
    switch (class)
    {
    case ip4c_A:
        printf("A");
        break;
    case ip4c_B:
        printf("B");
        break;
    case ip4c_C:
        printf("C");
        break;
    default:
        printf("Kulonleges celra fentartott cim.");
        break;
    }
}

void print_subnets(ipv4_addr_t addr, ipv4_mask_t subn_mask, uint8_t n_subnets, int binary_out)
{
    uint8_t orig_mask_bits = ipv4_class_default_mask_bits(ipv4_addr_class(addr));
    ipv4_mask_t orig_mask = ipv4_mask_generate(orig_mask_bits);

    uint8_t subn_mask_bits = ipv4_mask_bits(subn_mask);

    addr = addr & orig_mask;

    for (uint8_t i = 0; i < n_subnets; i++)
    {
        ipv4_addr_t subnet_addr;
        subnet_addr = addr | (i << (32 - subn_mask_bits));
        printf("%u. alhalozat:\n", i + 1);
        printf("Alhalozat cime:        "); PRINT_IPV4_ADDR(subnet_addr,                    binary_out); putchar('\n');
        printf("Elso kioszthato cim:   "); PRINT_IPV4_ADDR(subnet_addr + 1,                binary_out); putchar('\n');
        printf("Utolso kioszthato cim: "); PRINT_IPV4_ADDR((subnet_addr | ~subn_mask) - 1, binary_out); putchar('\n');
        printf("Broadcast cim:         "); PRINT_IPV4_ADDR(subnet_addr | ~subn_mask,       binary_out); putchar('\n'); putchar('\n');
    }
}
