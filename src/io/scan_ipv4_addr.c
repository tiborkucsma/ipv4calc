#include "ipv4io.h"

#include "ipv4types.h"
#include "ipv4math.h"
#include "ipv4utils.h"

#include <stdio.h>
#include <inttypes.h>

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
