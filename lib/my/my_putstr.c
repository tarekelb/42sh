/*
** EPITECH PROJECT, 2018
** my_putstr.c
** File description:
** print string characters
*/

#include <unistd.h>

int my_putstr(char const *str)
{
    unsigned long len = -1;

    if (!str)
        return (-1);
    if (str) {
        while (str[++len]);
        write(1, str, len);
    }
    return (0);
}
