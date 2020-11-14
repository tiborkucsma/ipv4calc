#pragma once

#include "ip4types.h"
#include <inttypes.h>

/**
 * @brief Kiir egy byteot binaris formaban
 * 
 * @param byte Kiirando byte
 */
void print_byte_bin(uint8_t byte);




/**
 * @brief Kiir egy ipv4-es cimet binaris formaban
 * 
 * @param addr Kiirando cim
 */
void print_ipv4_addr_bin(ipv4_addr_t addr);
/**
 * @brief Kiir egy ipv4-es cimet decimalis formaban
 * 
 * @param addr Kiirando cim 
 */
void print_ipv4_addr_dec(ipv4_addr_t addr);
/**
 * @brief Kiir egy ipv4-es maszkot binaris formaban
 * 
 * @param mask Kiirando maszk
 */
void print_ipv4_mask_bin(ipv4_mask_t mask);
/**
 * @brief Kiir egy ipv4-es maszkot decimalis formaban
 * 
 * @param mask Kiirando maszk
 */
void print_ipv4_mask_dec(ipv4_mask_t mask);

#define PRINT_IPV4_ADDR(addr, b) if (b) print_ipv4_addr_bin(addr); else print_ipv4_addr_dec(addr);
#define PRINT_IPV4_MASK(mask, b) if (b) print_ipv4_addr_bin(mask); else print_ipv4_addr_dec(mask);




/**
 * @brief Beolvas egy ipv4-es cimet a felhasznalotol
 * 
 * @return Beolvasott cim
 */
ipv4_addr_t scan_ipv4_addr();
/**
 * @brief Beolvas egy ipv4-es maszkot a felhasznalotol
 * 
 * @return Beolvasott maszk
 */
ipv4_mask_t scan_ipv4_mask();
/**
 * @brief Beolvas egy ipv4-es cimet a egy stringbol
 * 
 * @return Beolvasott cim
 */
ipv4_addr_t scan_ipv4_addr_str(const char *str);
/**
 * @brief Beolvas egy ipv4-es maszkot a egy stringbol
 * 
 * @return Beolvasott maszk
 */
ipv4_mask_t scan_ipv4_mask_str(const char *str);




/**
 * @brief Kiirja egy ipv4-es osztály betujelet
 * 
 */
void print_ipv4_class_name(ipv4_class_t class);




/**
 * @brief Kiirja n_subnets alhalozatot, egy ipv4-es cim és maszk alapjan
 * 
 * @param addr Egy ipv4-es cim
 * @param subn_mask Az alhalozati maszk
 * @param n_subnets A kiirando alhalozatok szama
 * @param binary_out Binaris legyen-e a kimenet
 */
void print_subnets(ipv4_addr_t addr, ipv4_mask_t subn_mask, uint8_t n_subnets, int binary_out);
