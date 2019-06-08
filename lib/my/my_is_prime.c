/*
** EPITECH PROJECT, 2018
** my_is_prime.c
** File description:
** search if number is prime or not
*/

int my_is_prime(int nb)
{
    int max = nb / 2;
    int value = 1;

    if (nb < 1)
        return (0);
    if (nb == 1)
        return (1);
    while (++value <= max) {
        if (nb % value == 0)
            return (0);
    }
    return (1);
}
