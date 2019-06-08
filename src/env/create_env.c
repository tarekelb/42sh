/*
** EPITECH PROJECT, 2018
** create_env.c
** File description:
** create env
*/

#include "ftsh.h"

list_t *create_link_env(list_t *list, char *id, char *data)
{
    list_t *new = calloc(1, sizeof(list_t));
    list_t *tmp;

    strcat(new->id, id);
    strcat(new->data, data);
    new->next = NULL;
    new->prev = list;
    if (!list)
        return (new);
    for (tmp = list; tmp->next; tmp = tmp->next);
    tmp->next = new;
    new->prev = tmp;
    return (list);
}

list_t *create_list_env(char **env)
{
    list_t *env_list = NULL;
    int index_bis = 0;
    char list_name[CMD_SIZE / 2];

    if (!env)
        return (NULL);
    for (int index = 0; env[index]; index++) {
        for (index_bis = 0; env[index][index_bis] && \
        env[index][index_bis] != '='; index_bis++)
            list_name[index_bis] = env[index][index_bis];
        list_name[index_bis] = '\0';
        env_list = create_link_env(env_list, list_name, env[index] + \
        (env[index][index_bis] ? index_bis + 1 : index_bis));
    }
    return (env_list);
}
