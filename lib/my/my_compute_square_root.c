/*
** EPITECH PROJECT, 2018
** my_compute_square_root.c
** File description:
** make a square root
*/

int my_compute_square_root(int nb)
{
    for (int i = 0; i <= nb / 2 + 1; ++i)
        if (i * i == nb)
        return (i);
    return (0);
}
