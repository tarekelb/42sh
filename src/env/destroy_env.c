/*
** EPITECH PROJECT, 2018
** destroy_env.c
** File description:
** destroy env
*/

#include "ftsh.h"

void destroy_env(char **env)
{
    if (!env)
        return;
    for (int index = 0; env[index]; index++)
        free(env[index]);
    free(env);
}

void destroy_list_env(list_t *env_list)
{
    if (!env_list)
        return;
    destroy_list_env(env_list->next);
    free(env_list);
}
