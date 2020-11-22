#pragma once

#include "ipv4types.h"

#include <inttypes.h>

/**
 * @brief Megadja egy cim n-edik oktettjét
 * 
 * @param addr Cim
 * @param n Oktett szama
 * @return Oktett
 */
uint8_t      ipv4_addr_octet(ipv4_addr_t addr, uint8_t n);
/**
 * @brief Megadja egy maszk n-edik oktettjét
 * 
 * @param addr Maszk
 * @param n Oktett szama
 * @return Oktett
 */
uint8_t      ipv4_mask_octet(ipv4_mask_t mask, uint8_t n);




/**
 * @brief Megadja egy ip cimrol hogy privat-e
 * 
 * @param addr Az ip cim
 * @return 1 ha privat, 0 kulonben
 */
int          ipv4_addr_private(ipv4_addr_t addr);




/**
 * @brief Meghatarozza egy ip cim osztalyat
 * 
 * @param addr A cim
 * @return Az osztaly
 */
ipv4_class_t ipv4_addr_class(ipv4_addr_t addr);




/**
 * @brief Meghatarozza az egyes bitek szamat egy osztaly alapertelmezett maszkjaban
 * 
 * @return Egyes bitek szama
 */
uint8_t     ipv4_class_default_mask_bits(ipv4_class_t class);




/**
 * @brief General egy maszkot n darab egyes bittel
 * 
 * @param n Egyes bitek szama
 * @return A maszk
 */
ipv4_mask_t  ipv4_mask_generate(uint8_t n);
/**
 * @brief Megszamolja egy maszk egyes bitjeit
 * 
 * @param mask A maszk
 * @return Az egyes bitek szama
 */
uint8_t     ipv4_mask_bits(ipv4_mask_t mask);
