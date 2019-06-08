/*
** EPITECH PROJECT, 2019
** set_unset_var
** File description:
** set_unset_var
*/

#include "ftsh.h"

int error_set_var_equal(char **cmd, char **tab)
{
    if (tab[1] && tab[2]) {
        write(2, "set: Too many arguments.\n", 25);
        return (-1);
    }
    if ((cmd[0][0] >= 91 && cmd[0][0] <= 96) || \
    cmd[0][0] < 'A' || cmd[0][0] > 'z') {
        write(2, "set: Variable name must begin with a letter.\n", 45);
        return (-1);
    }
    if (!my_str_isalpha(cmd[0])) {
        write(2, "set: Variable name must"
        " contain alphanumeric characters.\n", 57);
        return (-1);
    }
    return (0);
}

int error_set_var_not(char **cmd, int a)
{
    if (cmd[a + 3] && cmd[a + 4]) {
        write(2, "set: Too many arguments.\n", 25);
        return (-1);
    }
    if ((cmd[a + 1][0] >= 91 && cmd[a + 1][0] <= 96) || \
    cmd[a + 1][0] < 'A' || cmd[a + 1][0] > 'z') {
        write(2, "set: Variable name must begin with a letter.\n", 45);
        return (-1);
    } else if (!my_str_isalpha(cmd[a + 1])) {
        write(2, "set: Variable name must"
        " contain alphanumeric characters.\n", 57);
        return (-1);
    }
    return (0);
}

int set_env_var(shell_t *shell, char **tab, int a)
{
    char **tmp = NULL;

    if (tab[a + 1] && check_equal(tab[a + 1])) {
        tmp = my_str_to_word_array(tab[a + 1], "=");
        if (error_set_var_equal(tmp, tab) == -1) {
            free_tab(tmp);
            return (-1);
        }
        shell->var_list = create_link_env(shell->var_list, tmp[0], tmp[1]);
        free_tab(tmp);
    } else if (tab[a + 1] && tab[a + 2] && !strcmp(tab[a + 2], "=")) {
        if (error_set_var_not(tab, a) == -1)
            return (-1);
        shell->var_list = create_link_env(shell->var_list, \
        tab[a + 1], tab[a + 3]);
    }
    return (0);
}

int set_var(shell_t *shell, char **tab, int a)
{
    if (!strcmp(tab[a], "set")) {
        if (set_env_var(shell, tab, a) == -1)
            return (-1);
    }
    return (0);
}
