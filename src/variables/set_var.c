/*
** EPITECH PROJECT, 2019
** set_var.c
** File description:
** set_var
*/

#include "ftsh.h"

int check_equal(char *str)
{
    int a = 0;

    for (; str[a]; a += 1)
        if (str[a] == '=')
            return (a);
    return (0);
}

void unset_list_var(shell_t *shell, char *id)
{
    list_t *tmp;

    for (tmp = shell->var_list; tmp && my_strcmp(id, tmp->id); tmp = tmp->next);
    if (!tmp) {
        shell->error = 1;
        return;
    }
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    else
        shell->var_list = tmp->next;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    free(tmp);
}

void set_var_all_exec(shell_t *shell, tree_t *tree)
{
    for (int a = 0; tree->cmd[a]; a += 1)
        if (set_var(shell, tree->cmd, a) == -1) {
            return;
        }
}

int unset_var_all(shell_t *shell, char **tab, int a)
{
    if (!strcmp(tab[a], "unset")) {
        if (!tab[a + 1]) {
            write(2, "unset: Too few arguments.\n", 26);
            return (-1);
        }
        unset_list_var(shell, tab[a + 1]);
    }
    return (0);
}

void unset_var_exec(shell_t *shell, tree_t *tree)
{
    for (int a = 0; tree->cmd[a]; a += 1)
        if (unset_var_all(shell, tree->cmd, a) == -1)
            return;
}
