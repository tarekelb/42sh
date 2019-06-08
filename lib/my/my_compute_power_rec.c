/*
** EPITECH PROJECT, 2018
** my_compute_power_rec.c
** File description:
** make a pow
*/

int my_compute_power_rec(int nb, int p)
{
    double j;

    if (p == 0)
        return (1);
    if (p < 0)
        return (0);
    if (p > 0)
        j = nb * my_compute_power_rec(nb, p - 1);
    if (j > 2147483647)
        return (0);
    return (j);
}
