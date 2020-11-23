#include "ipv4io.h"

#include "ipv4types.h"
#include "ipv4math.h"
#include "ipv4utils.h"

#include <stdio.h>
#include <inttypes.h>

void print_subnet(subnet_t sn, int binary_out)
{
    printf("Alhalozat cime:\t\t");      PRINT_IPV4_ADDR(sn.addr,                  binary_out);
    putchar('\n');
    printf("Elso kioszthato cim:\t");   PRINT_IPV4_ADDR(sn.addr + 1,              binary_out);
    putchar('\n');
    printf("Utolso kioszthato cim:\t"); PRINT_IPV4_ADDR((sn.addr | ~sn.mask) - 1, binary_out);
    putchar('\n');
    printf("Broadcast cim:\t\t");       PRINT_IPV4_ADDR(sn.addr | ~sn.mask,       binary_out);
    putchar('\n');
    printf("Lehetseges eszkozok szama: %d", (sn.addr | ~sn.mask) - (sn.addr + 1));
    putchar('\n');
    putchar('\n');
}
