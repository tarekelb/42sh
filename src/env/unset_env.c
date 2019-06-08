/*
** EPITECH PROJECT, 2018
** unset_env.c
** File description:
** unset env
*/

#include "ftsh.h"

void unset_list_env(shell_t *shell, char *id)
{
    list_t *tmp;

    for (tmp = shell->env_list; tmp && my_strcmp(id, tmp->id); tmp = tmp->next);
    if (!tmp) {
        shell->error = 1;
        return;
    }
    if (tmp->prev)
        tmp->prev->next = tmp->next;
    else
        shell->env_list = tmp->next;
    if (tmp->next)
        tmp->next->prev = tmp->prev;
    free(tmp);
}
