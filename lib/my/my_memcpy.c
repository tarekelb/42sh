/*
** EPITECH PROJECT, 2018
** my_memcpy.c
** File description:
** cpy byte per byte
*/

#include <unistd.h>

void *my_memcpy(void *dest, const void *src, unsigned long len)
{
    char *d = dest;
    const char *s = src;

    if (!dest || !src)
        return (NULL);
    while (len--)
        *d++ = *s++;
    return (dest);
}
