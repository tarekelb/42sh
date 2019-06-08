/*
** EPITECH PROJECT, 2019
** utils_var
** File description:
** utils_var
*/

#include "ftsh.h"

int is_var(char *str)
{
    for (int a = 0; str[a]; a += 1)
        if (str[a] == '$' && str[a + 1] != ' ')
            return (1);
    return (0);
}

int offset_var(shell_t *shell)
{
    for (int a = 0; shell->command_line[a]; a += 1)
        if (shell->command_line[a] == '$')
            return (a);
    return (0);
}

int strlen_var(char *str, int n)
{
    int a = 0;

    for (; str[n] && str[n] != ' ' && str[n] != '\n' \
    && str[n] != '"'; a += 1, n += 1);
    return (a);

}

char *strcpy_var(char *dest, char *src, int n, int len)
{
    dest = calloc(CMD_SIZE, sizeof(char));

    for (int a = 0; a < len; n += 1, a += 1)
        dest[a] = src[n];
    return (dest);
}
