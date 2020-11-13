#pragma once

#include <inttypes.h>

/**
 * @brief Kiszamolja hogy hany bitet kell 1-esre alakitani a maszkban, ha n reszre szeretnenk osztani egy halozatot
 * 
 * @param n Igenyelt alhalozatok szama
 * @return Atalakitando bitek szama
 */
uint32_t bits_to_convert(uint32_t n);

/**
 * @brief 32 bites pozitiv egeszek hatvanyozasa
 * 
 * @param n Hatvany alap
 * @param k Kitevo
 * @return Hatvany 
 */
uint32_t pow_u32(uint32_t n, uint32_t k);
