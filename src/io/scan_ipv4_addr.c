#include "ipv4io.h"

#include "ipv4types.h"
#include "ipv4math.h"
#include "ipv4utils.h"

#include <stdio.h>
#include <inttypes.h>

int scan_ipv4_addr(ipv4_addr_t *addr)
{
    uint8_t a, b, c, d;
    int res = scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
    *addr |= a << 24;
    *addr |= b << 16;
    *addr |= c << 8;
    *addr |= d << 0;
    return res;
}

int scan_ipv4_addr_str(const char *str, ipv4_addr_t *addr)
{
    uint8_t a, b, c, d;
    int res = sscanf(str, "%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
    *addr |= a << 24;
    *addr |= b << 16;
    *addr |= c << 8;
    *addr |= d << 0;
    return res;
}
