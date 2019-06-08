/*
** EPITECH PROJECT, 2018
** my_swap.c
** File description:
** swap value
*/

void my_swap(int *a, int *b)
{
    int c = *a;

    *a = *b;
    *b = c;
}
