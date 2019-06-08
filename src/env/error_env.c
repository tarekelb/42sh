/*
** EPITECH PROJECT, 2019
** error_env.c
** File description:
** error_env
*/

#include "ftsh.h"

int error_handling_set(shell_t *shell, char **cmd)
{
    if ((cmd[1][0] >= 91 && cmd[1][0] <= 96) || \
    cmd[1][0] < 'A' || cmd[1][0] > 'z') {
        write(2, "setenv: Variable name must begin with a letter.\n", 48);
        shell->return_status = 1;
        return (1);
    } 
    if (!my_str_isalpha(cmd[1])) {
        write(2, "setenv: Variable name must"
        " contain alphanumeric characters.\n", 60);
        return (-1);
    }
    return (0);
}