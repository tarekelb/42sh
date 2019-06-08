/*
** EPITECH PROJECT, 2018
** my_isneg.c
** File description:
** print if number is positive or negative
*/

void my_putchar(char c);

int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    return (0);
}
