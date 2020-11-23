#pragma once
#include "process_args.h"

/**
 * @brief A help parancshoz tartozo parancs kezelo, kiirja a help menut
 * 
 * @param pad A program argumentum adatai
 * @return Siker esetén 0, egyebkent egy hibakod
 */
int command_handler_help(arg_data_t *pad);


/**
 * @brief Az ipinfo parancshoz tartozo parancs kezelo, kiirja a megadott ip osztalyat, alapertelmezett maszkjat, illetve hogy a megadott maszk alapjan ez minek a cime (halozat, szorasi, hoszt)
 * 
 * @param pad A program argumentum adatai
 * @return Siker esetén 0, egyebkent egy hibakod
 */
int command_handler_ipinfo(arg_data_t *pad);


/**
 * @brief A subnet parancshoz tartozo parancs kezelo, felbont egy halozatot n alhalora, es kiirja ezeket
 * 
 * @param pad A program argumentum adatai
 * @return Siker esetén 0, egyebkent egy hibakod
 */
int command_handler_subnet(arg_data_t *pad);


/**
 * @brief 
 * 
 * @param pad 
 * @return int 
 */
int command_handler_vlsm(arg_data_t *pad);


/**
 * @brief A wildcard parancshoz tartozo parancs kezelo, atalakit egy normal maszkot wildcard maszkra
 * 
 * @param pad A program argumentum adatai
 * @return Siker esetén 0, egyebkent egy hibakod
 */
int command_handler_wildcard(arg_data_t *pad);
