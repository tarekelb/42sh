/*
** EPITECH PROJECT, 2018
** manage_env_list.c
** File description:
** manage env list
*/

#include "ftsh.h"

char *get_data_env(list_t *env_list, char *id)
{
    if (!id)
        return (NULL);
    for (; env_list && my_strcmp(env_list->id, id); env_list = env_list->next);
    if (!env_list || my_strcmp(env_list->id, id))
        return (NULL);
    else
        return (env_list->data);
}

void update_env(shell_t *shell)
{
    int index = 0;
    char *path = get_data_env(shell->env_list, "PATH");

    for (list_t *tmp = shell->env_list; tmp; tmp = tmp->next, index++);
    shell->env = malloc(sizeof(char *) * (index + 1));
    shell->env[index] = NULL;
    index = 0;
    for (list_t *tmp = shell->env_list; tmp; tmp = tmp->next, index++) {
        shell->env[index] = calloc(CMD_SIZE * 2 + 1, sizeof(char));
        sprintf(shell->env[index], "%s=%s", tmp->id ? tmp->id : "", \
        tmp->data ? tmp->data : "");
    }
    if (path) {
        memset(shell->path, 0, sizeof(shell->path));
        strcpy(shell->path, path);
    }
}

void my_env_list(shell_t *shell, char **cmd)
{
    if (cmd[1]) {
        shell->return_status = 1;
        return;
    }
    display_list_env(shell->env_list);
    shell->return_status = 0;
}

void my_setenv_list(shell_t *shell, char **cmd)
{
    if (!cmd[1]) {
        my_env_list(shell, cmd);
        return;
    }
    if (cmd[2] && cmd[3]) {
        write(2, "setenv: Too many arguments.\n", 28);
        shell->return_status = 1;
        return;
    }
    if (error_handling_set(shell, cmd) == -1)
        return;
    set_list_env(shell, cmd[1], cmd[2] ? cmd[2] : "");
    destroy_env(shell->env);
    update_env(shell);
    shell->return_status = 0;
}

void my_unsetenv_list(shell_t *shell, char **cmd)
{
    if (!cmd[1]) {
        write(2, "unsetenv: Too few arguments.\n", 29);
        shell->return_status = 1;
        return;
    }
    unset_list_env(shell, cmd[1]);
    destroy_env(shell->env);
    update_env(shell);
    shell->return_status = 0;
}