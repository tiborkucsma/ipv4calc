#include "args/process_args.h"

#include <string.h>
#include <stdlib.h>
#include <ctype.h>

void process_args(arg_data_t *arg_data, int argc, char **argv)
{
    arg_data->n_cmdargs = 0;
    arg_data->cmd = NULL;
    
    memset(arg_data->setopts, 0, 128 * sizeof(int));

    for (int i = 1; i < argc && strcmp(argv[i], "--") != 0; i++)
    {
        if (argv[i][0] == '-')
        {
            for (int j = 1; argv[i][j]; j++)
            {
                if (isalnum(argv[i][j]))
                {
                    arg_data->setopts[argv[i][j]] = 1;
                }
            }
        } else if (arg_data->cmd == NULL)
        {
            arg_data->cmd = argv[i];
        } else if (arg_data->n_cmdargs < PROCESS_ARGS_MAX_CMD_ARGS)
        {
            arg_data->cmdargs[arg_data->n_cmdargs++] = argv[i];
        }
    }
}
