/*
** EPITECH PROJECT, 2018
** display_env.c
** File description:
** display env
*/

#include "ftsh.h"

void display_list_env(list_t *env_list)
{
    for (; env_list; env_list = env_list->next) {
        my_putstr(env_list->id);
        write(1, "=", 1);
        my_putstr(env_list->data ? env_list->data : "");
        write(1, "\n", 1);
    }
}

void display_env(char **env)
{
    if (!env)
        return;
    for (int index = 0; env[index]; index++) {
        my_putstr(env[index]);
        write(1, "\n", 1);
    }
}
