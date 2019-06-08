/*
** EPITECH PROJECT, 2018
** my_show_word_array.c
** File description:
** put each word in string in a array
*/

#include <unistd.h>

unsigned long my_strlen(char const *);

int my_show_word_array(char * const *tab)
{
    while (*tab) {
        write(1, tab, my_strlen(*tab));
        write(1, "\n", 1);
        ++tab;
    }
    return (0);
}
