/*
** EPITECH PROJECT, 2018
** alias.h
** File description:
** header file for alias
*/

#ifndef _ALIAS_H_
#define _ALIAS_H_

void add_alias(shell_t *shell, char *cmd, char **new);
int remove_alias(shell_t *shell, char *cmd);

void my_add_alias(shell_t *shell, char *cmd, char **new);
void my_remove_alias(shell_t *shell, char *cmd);
void replace_alias(shell_t *shell);

#endif
