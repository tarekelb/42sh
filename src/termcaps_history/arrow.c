/*
** EPITECH PROJECT, 2019
** file
** File description:
** arrow capture
*/

#include "ftsh.h"

void my_getchararrows(int c)
{
    if (c == 0) {
        while (my_kbhit()) {
            my_getch();
        }
    }
}

int find_arrow2(int c)
{
    switch (my_getch()) {
        case 'A':
            c = KEY_UP;
            break;
        case 'B':
            c = KEY_DOWN;
            break;
        case 'D':
            c = KEY_LEFT;
            break;
        case 'C':
            c = KEY_RIGHT;
            break;
        default:
            c = 0;
            break;
    }
    return (c);
}

int find_arrow(int c)
{
    if (c == '[') {
        c = find_arrow2(c);
    } else {
        c = 0;
    }
    return (c);
}

int my_getchararrow(void)
{
    int c;

    if (!my_kbhit())
        return (KEY_ESCAPE);
    c = my_getch();
    c = find_arrow(c);
    my_getchararrows(c);
    return (c);
}
