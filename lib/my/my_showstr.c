/*
** EPITECH PROJECT, 2018
** my_showstr.c
** File description:
** my_showstr.c
*/

void my_putchar(char c);

int my_putnbr_base(int nbr, char const *base);

int my_showstr(char const *str)
{
    for (int i = 0; str[i] != 0; i++) {
        if (str[i] < 32 || str[i] > 126) {
            my_putchar('\\');
            my_putnbr_base(str[i], "0123456789ABCDEF");
        } else
            my_putchar(str[i]);
    }
    return (0);
}
