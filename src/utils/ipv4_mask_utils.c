#include "ipv4utils.h"

#include "ipv4types.h"
#include "ipv4math.h"

#include <inttypes.h>

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
