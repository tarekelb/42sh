/*
** EPITECH PROJECT, 2019
** globbings.h
** File description:
** globbings
*/

#ifndef GLOBBINGS_H_
#define GLOBBINGS_H_

void replace_glob(shell_t *shell);
void where(shell_t *shell, char *cmd);
void replace_repeat(shell_t *shell);
void replace_quote(shell_t *shell);
void replace_inhib(shell_t *shell);
char *my_str_cat_space(char *str, char *str2);

#endif
