#include "ipv4utils.h"

#include "ipv4types.h"
#include "ipv4math.h"

#include <inttypes.h>

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
