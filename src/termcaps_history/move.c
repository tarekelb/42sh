/*
** EPITECH PROJECT, 2019
** PSU_42sh_2018
** File description:
** move up
*/

#include "ftsh.h"

int verif_return(char *str)
{
    if (str[0] == 0)
        return (1);
    for (int a = 0; str[a] == ' '; a++) {
        if (str[a] == 0)
            return (1);
    }
    return (0);
}

void my_tty(void)
{
    if (isatty(0) == 1)
        printf("$> ");
}

void move_up(shell_t *shell)
{
    shell->history_pos = history_find(shell->vector->test, \
    shell->command_history, shell->history_pos - 1);
    free(shell->vector->test);
    shell->vector->test = calloc(strlen\
    (shell->command_history[shell->history_pos]) + 2, sizeof(char));

    for (int a = 0; shell->command_history[shell->history_pos][a]; a++) {
        shell->vector->test[a] = shell->command_history[shell->history_pos][a];
    }
    shell->vector->size = strlen\
    (shell->command_history[shell->history_pos]);
    shell->vector->content = shell->vector->size;
    shell->vector->pos = shell->vector->content;
}

void move_down(shell_t *shell)
{
    shell->history_pos++;
    free(shell->vector->test);
    shell->vector->test = calloc(strlen\
    (shell->command_history[shell->history_pos]) + 2, sizeof(char));
    for (int a = 0; shell->command_history[shell->history_pos][a]; a++) {
        shell->vector->test[a] = shell->command_history[shell->history_pos][a];
    }
    shell->vector->size = strlen\
    (shell->command_history[shell->history_pos]);
    shell->vector->content = shell->vector->size;
    shell->vector->pos = shell->vector->content;
}
