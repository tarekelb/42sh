/*
** EPITECH PROJECT, 2019
** inhib.c
** File description:
** inhib
*/

#include "ftsh.h"

char find_inhib(char c)
{
    switch (c) {
        case 'n':
            return ('\n');
        case 't':
            return ('\t');
        case 'v':
            return ('\v');
        case '0':
            return ('\0');
        default:
            return (c);
    }
    return (c);
}

void replace_inhib_bis(shell_t *shell, int index)
{
    char c = find_inhib(shell->command_line[index + 1]);
    char tmp[CMD_SIZE] = {0};
    char *cmd;

    if (!shell->command_line[index + 1]) {
        shell->command_line[index] = 0;
        return;
    }
    strncpy(tmp, shell->command_line, index);
    cmd = calloc(strlen(shell->command_line) + 1, sizeof(char));
    sprintf(cmd, "%s%c%s", tmp, c, shell->command_line + index + 2);
    free(shell->command_line);
    shell->command_line = cmd;
}

void replace_inhib(shell_t *shell)
{
    for (int index = 0; shell->command_line[index]; index++) {
        if (shell->command_line[index] == '\\') {
            replace_inhib_bis(shell, index);
            index += (shell->command_line[index + 1]) ? 1 : 0;
        }
    }
}
