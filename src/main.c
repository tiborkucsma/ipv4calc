#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdlib.h>

#include "ip4utils.h"
#include "ip4types.h"
#include "ip4io.h"
#include "ip4math.h"
#include "args/process_args.h"

#include "args/command_handler_subnet.h"
#include "args/command_handler_wildcard.h"
#include "args/command_handler_ipinfo.h"
#include "args/command_handler_help.h"
typedef struct { int args; int (*handler)(arg_data_t *pad); const char name[128]; } command_data_t;
const command_data_t command_data[] = {
    { 2, &command_handler_subnet,   "subnet" },
    { 1, &command_handler_wildcard, "wildcard" },
    { 2, &command_handler_ipinfo,   "ipinfo" },
    { 0, &command_handler_help,     "help" },
    { 0, NULL, 0 }
};

int main(int argc, char *argv[])
{  
    arg_data_t parsed_argument_data;
    process_args(&parsed_argument_data, argc, argv);

    if (parsed_argument_data.cmd == NULL)
    {
        printf("Parancs megadasa kotelezo!\n\n");
        command_handler_help(&parsed_argument_data);
        return 1;
    }

    for (const command_data_t *cd = command_data; cd->name; cd++)
    {
        if (strcmp(cd->name, parsed_argument_data.cmd) == 0)
        {
            if (cd->args != parsed_argument_data.n_cmdargs)
            {
                printf("A(z) %s parancs %d parametert var.\n\n", parsed_argument_data.cmd, cd->args);
                command_handler_help(&parsed_argument_data);
                return 1;
            }

            if (cd->handler != NULL)
            {
                return cd->handler(&parsed_argument_data);
            }

            printf("Belso hiba! A parancs meg nincs implementalva.\n");
            return 0;
        }
    }
    
    printf("Ismeretlen parancs!\n\n");
    command_handler_help(&parsed_argument_data);
    return 1;
}
