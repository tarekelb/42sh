/*
** EPITECH PROJECT, 2019
** repeat.c
** File description:
** repeat
*/

#include "ftsh.h"

int my_strcmp_repeat(char *s1, char *s2, int size)
{
    int index = 0;

    if (!s1 || !s2)
        return (0);
    for (; index != size && s1[index] && s1[index] == s2[index]; index++);
    return (!s2[index]);
}

void replace_repeat_bis(shell_t *shell, int index)
{
    char tmp[CMD_SIZE] = {0};
    int repeat_nbr = my_getnbr(shell->command_line + index);
    char *cmd = calloc(strlen(shell->command_line) + \
    strlen(shell->command_line + index) * repeat_nbr, sizeof(char));

    strncpy(cmd, shell->command_line, index - 7);
    sprintf(tmp, " %s ;", shell->command_line + index + my_nbrlen(repeat_nbr));
    for (int index_bis = 0; index_bis < repeat_nbr; index_bis++)
        strcat(cmd, tmp);
    free(shell->command_line);
    shell->command_line = cmd;
}

void replace_repeat(shell_t *shell)
{
    for (int index = 0; shell->command_line[index]; index++) {
        if (my_strcmp_repeat(shell->command_line + index, "repeat ", 7) == 0)
            continue;
        replace_repeat_bis(shell, index + 7);
    }
}
