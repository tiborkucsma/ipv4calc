#include "ipv4io.h"

#include "ipv4types.h"
#include "ipv4math.h"
#include "ipv4utils.h"

#include <stdio.h>
#include <inttypes.h>

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

void print_ipv4_addr_dec(ipv4_addr_t addr)
{
    printf("%hhu.%hhu.%hhu.%hhu",
        ipv4_addr_octet(addr, 0),
        ipv4_addr_octet(addr, 1),
        ipv4_addr_octet(addr, 2),
        ipv4_addr_octet(addr, 3));
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
