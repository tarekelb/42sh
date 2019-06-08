/*
** EPITECH PROJECT, 2019
** cd.h
** File description:
** cd.h
*/

#ifndef CD_H_
#define CD_H_

int clean_cmd(char *cmd);
void classic_cd(char **tmp, shell_t *);
void manage_directory(shell_t *shell);
int clean_cmd(char *cmd);
int error_file(char **tmp);
void home_cd(char **tmp, shell_t *shell, int a);
void get_path(shell_t *, char *);
void old_cd(char **tmp, shell_t *shell, int a);
void free_tab(char **tab);

#endif
