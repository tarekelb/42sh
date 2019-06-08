/*
** EPITECH PROJECT, 2018
** malloc.c
** File description:
** fonctions for basic alloc
*/

#include <unistd.h>
#include <stdlib.h>

unsigned long my_strlen(char const *str);

char *my_concat(char *str1, char *str2)
{
    char *rtn;
    int i = 0;
    int j = 0;

    rtn = malloc((int)my_strlen((char const *)str1) + \
    (int)my_strlen((char const *)str2) + 10);
    for (; str1[i]; i++)
        rtn[i] = str1[i];
    for (; str2[j]; j++)
        rtn[j + i] = str2[j];
    rtn[j + i] = '\0';
    return (rtn);
}

void *my_malloc(size_t byte, size_t size, size_t n)
{
    void *rtn = malloc(byte * ((n == 1) ? size : n));

    if (!rtn)
        return (NULL);
    if (n == 1) {
        for (unsigned long i = 0; i < size; i += 1)
            ((unsigned char *)rtn)[i] = '\0';
        return (rtn);
    }
    for (unsigned long i = 0; i < n; i += 1)
        ((unsigned char **)rtn)[i] = NULL;
    return (rtn);
}
