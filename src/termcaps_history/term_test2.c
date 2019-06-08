/*
** EPITECH PROJECT, 2019
** file
** File description:
** arrow gestion
*/

#include "ftsh.h"

char *fill(char *str)
{
    return (str);
}

int my_getchar2(void)
{
    int c;

    c = my_getch();
    return ((c == KEY_ESCAPE) ? my_getchararrow() : c);
}

void history_move(shell_t *shell, int c)
{
    if (c == KEY_UP && shell->history_pos) {
        move_up(shell);
    }
    if (c == KEY_DOWN && \
    shell->command_history[shell->history_pos] != NULL) {
        if (shell->command_history[shell->history_pos + 1] != NULL)
            move_down(shell);
        else {
            free(shell->vector->test);
            create_vec(shell->vector);
            shell->history_pos++;
        }
    }
}

void my_getprint(vector_t *vector, int c)
{
    if (c == KEY_RIGHT) {
        if (vector->pos < vector->content) {
            cursorforward(1);
            vector->pos++;
        }
    } else if (c == KEY_LEFT) {
        if (vector->pos > 0) {
            cursorbackward(1);
            vector->pos--;
        }
    } else {
        if (c >= 32 && c <= 126) {
            add_vec(vector, vector->pos, c);
            vector->pos++;
        }
    }
}

void my_getchar(shell_t *shell)
{
    ini_get_char(shell);
    for (int c = my_getchar2(); c != EOF; c = my_getchar2()) {
        if (c == ENDOF)
            destroy_struct(shell);
        if (c == KEY_ENTER || c == '\n') {
            printf("\33[2K\r");
            my_tty();
            printf("%s\n", shell->vector->test);
            break;
        }
        if (c == KEY_DEL && shell->vector->content > 0) {
            remove_vec(shell->vector, shell->vector->pos);
            shell->vector->pos -= (shell->vector->pos > 0) ? 1 : 0;
        }
        getchar_cond(shell, c);
    }
    shell->command_line = realloc(shell->command_line, \
    my_strlen(shell->vector->test) + 10);
    strcpy(shell->command_line, shell->vector->test);
}
