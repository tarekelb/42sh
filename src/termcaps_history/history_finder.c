/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** history_finder
*/

#include "ftsh.h"

int str_finder(char *str, char *history)
{
    int a = 0;

    while (str[a] != 0) {
        if (history == NULL)
            return (1);
        if (history[a] == 0)
            return (1);
        if (str[a] != history[a])
            return (1);
        a++;
    }
    return (0);
}

int history_find(char *str, char **history, int pos)
{
    int a = pos;

    while (a > -1) {
        if (str_finder(str, history[a]) == 0) {
            return (a);
        }
        a--;
    }
    return (pos);
}

void ini_get_char(shell_t *shell)
{
    my_tty();
    if (verif_return(shell->vector->test) == 0) {
        shell->command_history = add_history\
        (shell->vector->test, shell->command_history);
        shell->history_len++;
        shell->history_pos = shell->history_len;
    }
    my_freestr(shell->vector);
}
