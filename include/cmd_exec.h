/*
** EPITECH PROJECT, 2019
** cmd_exec.h
** File description:
** header for cmd executor
*/

#ifndef CMD_EXEC_H_
#define CMD_EXEC_H_

void cmd_manager(shell_t *, tree_t *);
void cmd_executor(shell_t *, tree_t *);
char **find_cmd_path(shell_t *);
void clean_path_array(char **);
int sig_catch(int);

#endif
