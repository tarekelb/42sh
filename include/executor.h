/*
** EPITECH PROJECT, 2018
** executor.h
** File description:
** header file
*/

#ifndef _EXECUTOR_H_
#define _EXECUTOR_H_

void my_alias(shell_t *shell, tree_t *tree);
void my_unalias(shell_t *shell, tree_t *tree);
void my_exit(shell_t *shell, tree_t *tree);
void my_env(shell_t *shell, tree_t *tree);
void my_setenv(shell_t *shell, tree_t *tree);
void my_unsetenv(shell_t *shell, tree_t *tree);
void my_cd(shell_t *shell, tree_t *tree);
void my_where(shell_t *shell, tree_t *tree);

int exec_cmd_father(shell_t *shell, int pid, int fd[]);

void manage_error(int pid);
int bin_compatible(char *file);

#endif
