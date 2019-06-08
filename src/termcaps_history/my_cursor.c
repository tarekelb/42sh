/*
** EPITECH PROJECT, 2019
** file
** File description:
** cursor
*/

#include "ftsh.h"

void actualcursor(vector_t *vector)
{
    printf("\r");
    for (int stock = 0; stock < vector->pos + 3; stock++)
        cursorforward(1);
}

void my_freestr(vector_t *vector)
{
    free(vector->test);
    create_vec(vector);
}
