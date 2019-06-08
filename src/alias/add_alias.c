/*
** EPITECH PROJECT, 2018
** add_alias.c
** File description:
** add alias
*/

#include "ftsh.h"

void create_alias(alias_t *alias, char *cmd, char *new)
{
    memset(alias, 0, sizeof(alias_t));
    strcpy(alias->cmd, cmd);
    strcpy(alias->new, new);
}

void set_add_alias(char *tmp, char **cmd)
{
    strcat(tmp, cmd[0]);
    for (int index = 1; cmd[index]; index++) {
        strcat(tmp, " ");
        strcat(tmp, cmd[index]);
    }
}

void add_alias(shell_t *shell, char *cmd, char **new)
{
    unsigned int index = 0;
    char tmp[CMD_SIZE] = {0};

    set_add_alias(tmp, new);
    if (shell->alias_len == 0 || !shell->command_alias) {
        shell->command_alias = calloc(1, sizeof(alias_t));
        shell->alias_len = 1;
        return (create_alias(shell->command_alias, cmd, tmp));
    }
    for (; index != shell->alias_len && \
    my_strcmp(shell->command_alias[index].cmd, cmd); index++);
    if (index < shell->alias_len && \
    !my_strcmp(shell->command_alias[index].cmd, cmd)) {
        strcpy(shell->command_alias[index].new, tmp);
    } else {
        shell->command_alias = realloc(shell->command_alias, \
        (shell->alias_len + 1) * sizeof(alias_t));
        create_alias(&shell->command_alias[shell->alias_len], cmd, tmp);
        shell->alias_len += 1;
    }
}
