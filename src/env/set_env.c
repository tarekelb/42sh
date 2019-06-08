/*
** EPITECH PROJECT, 2018
** set_env.c
** File description:
** set env
*/

#include "ftsh.h"

void set_list_env(shell_t *shell, char *id, char *data)
{
    list_t *tmp;

    for (tmp = shell->env_list; tmp && my_strcmp(id, tmp->id); tmp = tmp->next);
    if (!tmp || my_strcmp(id, tmp->id)) {
        shell->env_list = create_link_env(shell->env_list, id, data);
        return;
    }
    strcpy(tmp->data, data);
}
