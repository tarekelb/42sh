/*
** EPITECH PROJECT, 2018
** my_calloc.c
** File description:
** theo gimenez
*/

#include <stdlib.h>

void *my_calloc(unsigned long n, unsigned long len, void *p)
{
    void *new = malloc(n * (p ? 1 : len));

    if (!new)
        return ((void *)0);
    if (!p)
        for (unsigned long i = 0; i < n * len; i += 1)
            ((unsigned char *)new)[i] = 0;
    else
        for (unsigned long i = 0; i < n; i += 1)
            ((unsigned char **)new)[i] = (void *)0;
    return (new);
}
