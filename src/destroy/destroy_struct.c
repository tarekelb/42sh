/*
** EPITECH PROJECT, 2018
** destroy_strcut.c
** File description:
** destroy strcut
*/

#include "ftsh.h"

void destroy_struct(shell_t *shell)
{
    destroy_env(shell->env);
    destroy_list_env(shell->env_list);
    if (shell->command_alias)
        free(shell->command_alias);
    if (shell->command_line)
        free(shell->command_line);
    free_my_vec(shell);
    destroy_history(shell);
    destroy_list_env(shell->var_list);
    if (shell->tree)
        clean_binary_tree(shell->tree);
    if (isatty(0) == 1)
        printf("exit\n");
    exit(0);
}
