#include "ipv4io.h"

#include "ipv4types.h"
#include "ipv4math.h"
#include "ipv4utils.h"

#include <stdio.h>
#include <inttypes.h>

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

void print_ipv4_mask_dec(ipv4_mask_t mask)
{
    printf("%hhu.%hhu.%hhu.%hhu",
        ipv4_mask_octet(mask, 0),
        ipv4_mask_octet(mask, 1),
        ipv4_mask_octet(mask, 2),
        ipv4_mask_octet(mask, 3));
}
