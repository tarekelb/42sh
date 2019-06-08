/*
** EPITECH PROJECT, 2018
** my_str_to_word_array.c
** File description:
** put word of str on array
*/

#include <stdlib.h>
#include <stdio.h>

int cmp_sep(char c, char *sep)
{
    for (int i = 0; sep[i] != 0; i += 1)
        if (sep[i] == c)
            return (1);
    return (0);
}

int my_count_word(char *str, char *sep)
{
    int len = 0;

    for (int i = 0; str[i] != 0; i += 1)
        if (cmp_sep(str[i], sep) == 0 && (cmp_sep(str[i + 1], sep) == 1 \
        || str[i + 1] == 0))
            ++len;
    return (len);
}

int my_word_len(char *str, char *sep)
{
    int len = 0;

    while (str[len] != 0 && cmp_sep(str[len], sep) == 0)
        ++len;
    return (len);
}

void *destroy_and_return(char **res, int j)
{
    for (; j > -1; j -= 1)
        free(res[j]);
    free(res);
    return (NULL);
}

char **my_str_to_word_array(char *str, char *sep)
{
    int words = my_count_word(str, sep);
    char **res = NULL;
    int word_len = 0;

    if (words < 1 || !(res = malloc(8 * (words + 1))))
        return (NULL);
    res[words] = NULL;
    for (int i = 0, j = 0; str[i] != 0 && j < words; j += 1) {
        for (; str[i] != 0 && cmp_sep(str[i], sep) == 1; ++i);
        word_len = my_word_len(str + i, sep);
        if (!(res[j] = malloc(word_len + 1)))
            return (destroy_and_return(res, j - 1));
        res[j][word_len] = 0;
        for (int k = 0; str[i] != 0 && cmp_sep(str[i], sep) == 0; k++, i++)
            res[j][k] = str[i];
    }
    return (res);
}
