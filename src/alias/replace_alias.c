/*
** EPITECH PROJECT, 2018
** replace_alias.c
** File description:
** replace alias
*/

#include "ftsh.h"

int my_strcmp_len(char *s1, char *s2, int size)
{
    int index = 0;

    if (!s1 || !s2)
        return (0);
    for (; index != size && s1[index] && s1[index] == s2[index]; index++);
    if (s1[index] == '&' || s1[index] == '&' || \
    s1[index] == '|' || s1[index] == '>' || s1[index] == '<' \
    || s1[index] == ' ' || !s1[index])
        return (1);
    else
        return (0);
    return (s2[index]);
}

int replace_alias_bis(shell_t *shell, char *cmd, int index)
{
    static char tmp[CMD_SIZE];
    char *new;

    for (unsigned int index_bis = 0; index_bis != \
    shell->alias_len; index_bis++) {
        if (my_strcmp_len(cmd + index, shell->command_alias[index_bis].cmd, \
        strlen(shell->command_alias[index_bis].cmd))) {
            memset(tmp, 0, CMD_SIZE);
            strncpy(tmp, cmd, index);
            new = calloc(strlen(cmd) + \
            strlen(shell->command_alias[index_bis].new) - \
            strlen(shell->command_alias[index_bis].cmd) + 1, sizeof(char));
            sprintf(new, "%s%s%s", tmp, shell->command_alias[index_bis].new, \
            cmd + (index + strlen(shell->command_alias[index_bis].cmd)));
            free(cmd);
            shell->command_line = new;
            return (0);
        }
    }
    return (index);
}

void replace_alias(shell_t *shell)
{
    if (!shell->command_line)
        return;
    for (int index = 0; shell->command_line[index]; index++)
        if (!index || shell->command_line[index - 1] == '&' || \
        shell->command_line[index - 1] == '&' || \
        shell->command_line[index - 1] == '|' || \
        shell->command_line[index - 1] == '>' || \
        shell->command_line[index - 1] == '<' || \
        shell->command_line[index - 1] == ' ')
            index = replace_alias_bis(shell, shell->command_line, index);
}
