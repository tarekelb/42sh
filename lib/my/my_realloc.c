/*
** EPITECH PROJECT, 2018
** my_realloc.c
** File description:
** theo gimenez
*/

#include <stdlib.h>

void *my_realloc_array(void *ptr, unsigned long size, unsigned long old_s, \
unsigned long len)
{
    void *new = malloc(size * len);
    unsigned long i = 0;

    if (!new)
        return ((void *)0);
    for (; i < size / 8 && i < old_s / 8; ++i)
        for (unsigned long j = 0; j != len; ++j)
            ((unsigned char **)new)[i][j] = ((unsigned char **)ptr)[i][j];
    for (; i < size; i += 1)
        ((unsigned char **)new)[i] = (void *)0;
    free(ptr);
    return (new);
}

void *my_realloc(void *ptr, unsigned long size, unsigned long old_s)
{
    void *new = malloc(size);
    unsigned long i = 0;

    if (!new)
        return ((void *)0);
    for (; i < size && i < old_s; i += 1)
        ((unsigned char *)new)[i] = ((unsigned char *)ptr)[i];
    for (; i < size; i += 1)
        ((unsigned char *)new)[i] = 0;
    free(ptr);
    return (new);
}
