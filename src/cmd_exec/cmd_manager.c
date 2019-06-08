/*
** EPITECH PROJECT, 2019
** cmd_manager.c
** File description:
** manage execution of commande
*/

#include "ftsh.h"

void cmd_manager(shell_t *shell, tree_t *tree)
{
    static const char *cmd[] = {"exit", "env", "setenv", "unsetenv", "cd", \
    "alias", "unalias", "set", "unset", "where", "which"};
    static void (*cmd_fct[])(shell_t *, tree_t *) = {my_exit, \
    my_env, my_setenv, my_unsetenv, my_cd, my_alias, my_unalias, \
    set_var_all, unset_var, my_where, my_where};
    unsigned int index = 0;

    for (; index < sizeof(cmd_fct) / sizeof(void *); ++index)
        if (!strcmp(*tree->cmd, cmd[index])) {
            cmd_fct[index](shell, tree);
            break;
        }
    if (index == sizeof(cmd_fct) / sizeof(void *))
        cmd_executor(shell, tree);
}
