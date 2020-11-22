#pragma once

#include <inttypes.h>

/**
 * @brief IPv4 cim tipus (4 bajtos elojel nelkuli egesz)
 * 
 */
typedef uint32_t ipv4_addr_t;

/**
 * @brief IPv4 maszk tipus (4 bajtos elojel nelkuli egesz)
 * 
 */
typedef uint32_t ipv4_mask_t;

/**
 * @brief IPv4 osztaly tipus (D es E osztaly nem kezelt)
 * 
 */
typedef enum { ip4c_A = 1, ip4c_B, ip4c_C, ip4c_D, ip4c_E, ip4c_UD } ipv4_class_t;
