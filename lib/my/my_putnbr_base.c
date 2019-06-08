/*
** EPITECH PROJECT, 2018
** my_putnbr_base.c
** File description:
** print a number in base x
*/

void my_putchar(char c);

int my_putnbr_base(int nbr, char const *base)
{
    int i = -1;

    if (!base)
        return (0);
    while (base[++i] != 0);
    if (nbr >= i)
        my_putnbr_base(nbr / i, base);
    my_putchar(base[nbr % i]);
    return (0);
}
