/*
** EPITECH PROJECT, 2018
** env.h
** File description:
** header file for env
*/

#ifndef _ENV_H_
#define _ENV_H_

list_t *create_link_env(list_t *list, char *id, char *data);
void unset_list_env(shell_t *shell, char *id);
void set_list_env(shell_t *shell, char *id, char *data);
void update_env(shell_t *shell);
void destroy_env(char **env);
void destroy_list_env(list_t *env_list);
char **emergency_env(void);
void display_list_env(list_t *env_list);
void display_env(char **env);
list_t *create_list_env(char **env);
char *get_data_env(list_t *env_list, char *id);

void my_env_list(shell_t *shell, char **cmd);
void my_setenv_list(shell_t *shell, char **cmd);
void my_unsetenv_list(shell_t *shell, char **cmd);
int error_handling_set(shell_t *shell, char **cmd);

#endif
