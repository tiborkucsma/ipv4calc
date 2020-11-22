#include "ipv4io.h"

#include "ipv4types.h"
#include "ipv4math.h"
#include "ipv4utils.h"

#include <stdio.h>
#include <inttypes.h>

int scan_ipv4_mask(ipv4_mask_t *mask)
{
    uint8_t a, b, c, d;
    int res = scanf("%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
    *mask = a << 24;
    *mask |= b << 16;
    *mask |= c << 8;
    *mask |= d << 0;
    return res;
}

int scan_ipv4_mask_str(const char *str, ipv4_mask_t *mask)
{
    uint8_t a, b, c, d;
    int res = sscanf(str, "%hhu.%hhu.%hhu.%hhu", &a, &b, &c, &d);
    *mask = a << 24;
    *mask |= b << 16;
    *mask |= c << 8;
    *mask |= d << 0;
    return res;
}
