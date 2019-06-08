/*
** EPITECH PROJECT, 2018
** add_alias.c
** File description:
** add alias
*/

#include "ftsh.h"

void my_add_alias(shell_t *shell, char *cmd, char **new)
{
    shell->return_status = 0;
    if (!cmd || !new || !*new)
        return;
    add_alias(shell, cmd, new);
}

void my_remove_alias(shell_t *shell, char *cmd)
{
    if (!cmd) {
        write(2, "unalias: Too few arguments.\n", 28);
        shell->return_status = 1;
        return;
    }
    remove_alias(shell, cmd);
    shell->return_status = 0;
}
