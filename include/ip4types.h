#pragma once

#include <inttypes.h>

/*typedef union
{
    uint32_t addr;
    uint8_t  oct[4];
} ipv4_addr_t;

typedef union
{
    uint32_t mask;
    uint8_t  oct[4];
} ipv4_mask_t;*/

typedef uint32_t ipv4_addr_t;

typedef uint32_t ipv4_mask_t;

typedef enum { ip4c_A = 1, ip4c_B, ip4c_C, ip4c_UD } ipv4_class_t;
