/*
** EPITECH PROJECT, 2018
** my_strlen.c
** File description:
** count string lenght
*/

unsigned long my_arraylen(void * const *ptr)
{
    unsigned long i = -1;

    if (!ptr)
        return (0);
    while (ptr[++i]);
    return (i);
}
