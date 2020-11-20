#include "ipv4utils.h"

#include "ipv4types.h"
#include "ipv4math.h"

#include <inttypes.h>

uint8_t ipv4_addr_octet(ipv4_addr_t addr, uint8_t n)
{
    return (addr >> ((3 - n) * 8)) & 0x000000ff;
}

uint8_t ipv4_mask_octet(ipv4_mask_t mask, uint8_t n)
{
    return (mask >> ((3 - n) * 8)) & 0x000000ff;
}
