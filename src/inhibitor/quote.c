/*
** EPITECH PROJECT, 2019
** quote.c
** File description:
** quote
*/

#include "ftsh.h"

int replace_quote_bis(shell_t *shell, int index, char c)
{
    int index_bis = index + 1;
    char tmp[CMD_SIZE] = {0};
    char *cmd;

    for (; shell->command_line[index_bis] && \
    shell->command_line[index_bis] != c; index_bis++);
    if (!shell->command_line[index_bis])
        return (index_bis);
    strncpy(tmp, shell->command_line + index + 1, index_bis - index - 1);
    cmd = calloc(strlen(shell->command_line) + 2, sizeof(char));
    strncpy(cmd, shell->command_line, index);
    strcat(cmd, tmp);
    memset(tmp, 0, sizeof(tmp));
    strcpy(tmp, shell->command_line + index_bis + 1);
    strcat(cmd, tmp);
    free(shell->command_line);
    shell->command_line = cmd;
    return (index_bis);
}

void replace_quote(shell_t *shell)
{
    for (int index = 0; shell->command_line[index]; index++) {
        if ((!index && shell->command_line[index] == '\"') || \
        (index && shell->command_line[index] == '\"' && \
        shell->command_line[index - 1] != '\\'))
            index = replace_quote_bis(shell, index, '\"');
    }
    for (int index = 0; shell->command_line[index]; index++) {
        if ((!index && shell->command_line[index] == '\'') || \
        (index && shell->command_line[index] == '\'' && \
        shell->command_line[index - 1] != '\\'))
            index = replace_quote_bis(shell, index, '\'');
    }
}
