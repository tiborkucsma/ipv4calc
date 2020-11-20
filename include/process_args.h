#pragma once

#define PROCESS_ARGS_MAX_CMD_ARGS 128

typedef struct
{
    int n_cmdargs;
    int setopts[128];
    char *cmd;
    char *cmdargs[PROCESS_ARGS_MAX_CMD_ARGS];
} arg_data_t;

/**
 * @brief Feldolgozza a program argumentumait
 * 
 * @param arg_data Ez lesz a feldolgozas eredmenye
 * @param argc A main azonos nevu valtozoja
 * @param argv A main azonos nevu valtozoja
 */
void process_args(arg_data_t *arg_data, int argc, char **argv);
