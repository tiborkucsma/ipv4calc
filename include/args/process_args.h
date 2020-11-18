#pragma once

#define PROCESS_ARGS_MAX_CMD_ARGS 128

typedef struct
{
    int n_cmdargs;
    int setopts[128];
    char *cmd;
    char *cmdargs[PROCESS_ARGS_MAX_CMD_ARGS];
} arg_data_t;

void process_args(arg_data_t *arg_data, int argc, char **argv);
