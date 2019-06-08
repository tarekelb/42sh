/*
** EPITECH PROJECT, 2018
** remove_alias.c
** File description:
** remove alias
*/

#include "ftsh.h"

void remove_alias_index(shell_t *shell, unsigned int remove_index)
{
    alias_t *new_command_alias;

    if (shell->alias_len <= 1) {
        free(shell->command_alias);
        shell->command_alias = NULL;
        shell->alias_len = 0;
        return;
    }
    shell->alias_len -= 1;
    new_command_alias = calloc(shell->alias_len, sizeof(alias_t));
    for (unsigned int index = 0; index != shell->alias_len; index++) {
        if (index < remove_index)
            new_command_alias[index] = shell->command_alias[index];
        else
            new_command_alias[index] = shell->command_alias[index + 1];
    }
    free(shell->command_alias);
    shell->command_alias = new_command_alias;
}

int remove_alias(shell_t *shell, char *cmd)
{
    unsigned int index = 0;

    if (shell->alias_len == 0 || !shell->command_alias)
        return (-1);
    for (; index != shell->alias_len && \
    my_strcmp(shell->command_alias[index].new, cmd); index++);
    if (index < shell->alias_len && \
    !my_strcmp(shell->command_alias[index].new, cmd)) {
        remove_alias_index(shell, index);
        return (0);
    } else {
        return (-1);
    }
}
