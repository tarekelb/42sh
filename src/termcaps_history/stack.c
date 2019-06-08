/*
** EPITECH PROJECT, 2019
** test_folder
** File description:
** stack
*/

#include "ftsh.h"

void create_vec(vector_t *vector)
{
    vector->test = calloc(1, sizeof(char));
    vector->size = 0;
    vector->content = 0;
    vector->pos = 0;
}

char *my_realloc_str(char *str, int a)
{
    char *str2 = calloc(a, 1);

    str2 = strcpy(str2, str);
    free(str);
    return (str2);
}

void vec_realloc(vector_t *vector)
{
    vector->test = my_realloc_str(vector->test, vector->size + 2);
    vector->size++;
}

void add_vec(vector_t *vector, int pos, char c)
{
    int pos1 = vector->content;

    if (vector->content == vector->size)
        vec_realloc(vector);
    while (pos < pos1) {
        vector->test[pos1] = vector->test[pos1 - 1];
        pos1--;
    }
    vector->test[pos] = c;
    vector->content++;
}

void remove_vec(vector_t *vector, int pos)
{
    int pos1 = pos - 1 ;
    int mcontent = vector->content - 1;

    if (pos > 0) {
        while (pos1 < mcontent + 1) {
            vector->test[pos1] = vector->test[pos1 + 1];
            pos1++;
        }
        vector->test[mcontent] = 0;
        vector->content--;
    }
}
