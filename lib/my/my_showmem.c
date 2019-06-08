/*
** EPITECH PROJECT, 2018
** my_showmem.c
** File description:
** my_showmem.c
*/

void my_putchar(char c);

void my_putstr(char *str);

int my_putnbr_base(int nbr, char const *base);

int my_strlen(char const *str);

void display_str(char const *str, int size)
{
    for (int i = 0; i < size; i++) {
        if (str[i] < 32 || str[i] > 126)
            my_putchar('.');
        else
            my_putchar(str[i]);
    }
    my_putchar('\n');
}

void char_address(char const *str, int size)
{
    int i;

    for (i = 0; i < size; i++) {
        if (str[i] < 16)
            my_putchar('0');
        my_putnbr_base(str[i], "0123456789ABCDEF");
        if (i % 2 == 1)
            my_putchar(' ');
    }
    for (i = i; i < 16; i++) {
        my_putchar(' ');
        my_putchar(' ');
        if (i % 2 == 1)
            my_putchar(' ');
    }
}

void line_address(int size)
{
    int tmp = size;
    int i = 0;

    while (tmp >= 16) {
        tmp /= 16;
        ++i;
    }
    for (int j = 0; j < 7 - i; j++)
        my_putchar('0');
    my_putnbr_base(size, "0123456789ABCDEF");
}

int my_showmem(char const *str, int size)
{
    int i;

    for (i = 0; i + 16 < size; i += 16) {
        line_address(i);
        my_putstr(":  ");
        char_address(str + i, 16);
        display_str(str + i, 16);
    }
    line_address(i);
    my_putstr(":  ");
    char_address(str + i, size - i);
    display_str(str + i, size - i);
    return (0);
}
