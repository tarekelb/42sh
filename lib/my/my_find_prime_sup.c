/*
** EPITECH PROJECT, 2018
** my_find_prime_sup.c
** File description:
** find equal or greater prime nb given
*/

int my_is_prime(int nb);

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb) == 1)
        return (nb);
    return (my_find_prime_sup(nb + 1));
}