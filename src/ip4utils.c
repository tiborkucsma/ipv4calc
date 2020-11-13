#include "ip4utils.h"

#include "ip4types.h"
#include "ip4math.h"

#include <inttypes.h>

uint8_t ipv4_addr_octet(ipv4_addr_t addr, uint8_t n)
{
    return (addr >> ((3 - n) * 8)) & 0x000000ff;
}

uint8_t ipv4_mask_octet(ipv4_mask_t mask, uint8_t n)
{
    return (mask >> ((3 - n) * 8)) & 0x000000ff;
}

ipv4_class_t ipv4_addr_class(ipv4_addr_t addr)
{
    if ((ipv4_addr_octet(addr, 0) >> 7) == 0 && ipv4_addr_octet(addr, 0) > 0) return ip4c_A;
    if ((ipv4_addr_octet(addr, 0) >> 6) == 2) return ip4c_B;
    if ((ipv4_addr_octet(addr, 0) >> 5) == 6) return ip4c_C;
    return ip4c_UD;
}

uint8_t ipv4_class_default_mask_bits(ipv4_class_t class)
{
    static const uint8_t class_mask_bits[] = { 0, 8, 16, 24, 0 };
    return class_mask_bits[class];
}

ipv4_mask_t ipv4_mask_generate(uint8_t n)
{
    ipv4_mask_t res;

    res = (pow_u32(2, n) - 1) << (32 - n);

    return res;
}

uint8_t ipv4_mask_bits(ipv4_mask_t mask)
{
    int n_bits = 0;
    for (; mask != 0; mask = mask << 1, n_bits++);
    return n_bits;
}
