/*
** EPITECH PROJECT, 2019
** test_folder
** File description:
** historic gestion
*/

#include "ftsh.h"

history_t *create_history(void)
{
    history_t *vector = malloc(sizeof(history_t));

    vector->str = calloc(1, sizeof(char *));
    vector->pos = 0;
    return (vector);
}

char **add_history(char *func, char **str)
{
    int a = 0;
    char **str2 = NULL;

    for (; str[a] != NULL; a++);
    str2 = calloc(a + 2, sizeof(char *));
    a = 0;
    for (; str[a]; a++) {
        str2[a] = calloc(strlen(str[a]) + 2, sizeof(char));
        for (int b = 0; str[a][b]; b++)
            str2[a][b] = str[a][b];
    }
    str2[a] = calloc(strlen(func) + 2, sizeof(char));
    for (int b = 0; func[b]; b++)
        str2[a][b] = func[b];
    for (int i = 0; str[i]; i++)
        free(str[i]);
    free(str);
    return (str2);
}

char **my_realloc2(char **str, int a)
{
    char **str2 = calloc(a, sizeof(char *));

    for (int b = 0; str2[b]; b++) {
        str2[b] = strcpy(str2[b], str[b]);
        free(str[b]);
    }
    free(str);
    return (str2);
}

void destroy_history(shell_t *shell)
{
    if (!shell->command_history)
        return;
    for (int a = 0; shell->command_history[a]; a++) {
        free(shell->command_history[a]);
    }
    free(shell->command_history);
}

void getchar_cond(shell_t *shell, int c)
{
    if (c == KEY_ESCAPE || c == KEY_UP || c == KEY_DOWN) {
        history_move(shell, c);
        printf("\33[2K\r");
        my_tty();
        printf("%s", shell->vector->test);
        actualcursor(shell->vector);
    } else {
        my_getprint(shell->vector, c);
        printf("\33[2K\r");
        my_tty();
        printf("%s", shell->vector->test);
        actualcursor(shell->vector);
    }
}
