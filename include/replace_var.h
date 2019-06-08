/*
** EPITECH PROJECT, 2019
** replace_var
** File description:
** replace_var
*/

#ifndef REPLACE_VAR_H_
#define REPLACE_VAR_H_

int is_var(char *str);
int offset_var(shell_t *shell);
int strlen_var(char *str, int n);
char *strcpy_var(char *dest, char *src, int n, int len);
void replace_var(shell_t *shell);
int error_set_var_equal(char **cmd, char **tab);
int error_set_var_not(char **cmd, int a);
int set_var(shell_t *shell, char **tab, int a);
void set_and_unset_var(shell_t *shell);
void unset_list_var(shell_t *shell, char *id);
int check_equal(char *str);
void unset_var(shell_t *shell_t, tree_t *tree);
void set_var_all(shell_t *shell, tree_t *tree);
int unset_var_all(shell_t *shell, char **tab, int a);
void set_var_all_exec(shell_t *, tree_t *);
void unset_var_exec(shell_t *, tree_t *);

#endif
