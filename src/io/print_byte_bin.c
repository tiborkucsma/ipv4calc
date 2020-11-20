#include "ipv4io.h"

#include <stdio.h>
#include <inttypes.h>

void print_byte_bin(uint8_t byte)
{
    for (int8_t i = 7; i >= 0; --i)
    {
        printf("%u", byte >> i & 1);
    }
}
