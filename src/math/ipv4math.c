#include "ipv4math.h"

#include <inttypes.h>

uint32_t bits_to_convert(uint32_t n)
{
    uint32_t p = 0;
    for (uint32_t i = 1; i < n && i != 0; i *= 2, p++);
    return p;
}

uint32_t pow_u32(uint32_t n, uint32_t k)
{
    uint32_t res = 1;
    for (uint32_t i = 0; i < k; i++)
    {
        res *= n;
    }
    return res;
}
