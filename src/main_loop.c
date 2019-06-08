/*
** EPITECH PROJECT, 2019
** main_loop.c
** File description:
** main loop of display
*/

#include "ftsh.h"

void my_get_line(shell_t *shell)
{
    unsigned long n = 0;
    int gl = 0;

    if (shell->command_line)
        free(shell->command_line);
    gl = getline(&shell->command_line, &n, stdin);
    if (gl == -1) {
        destroy_struct(shell);
        exit(0);
    }
    shell->command_line[gl - 1] = shell->command_line[gl - 1] == 10 \
    ? 0 : shell->command_line[gl - 1];
}

int clean_cmd(char *cmd)
{
    for (int i = 0; cmd[i] != 0; i += 1) {
        if (cmd[i] == ';' && i > 0 && cmd[i - 1] == ';')
            cmd[i - 1] = 32;
        if (cmd[i] == '<' && cmd[i + 1] == '<' && cmd[i + 2] == '<') {
            write(2, "Missing name for redirect.", 26);
            return (-1);
        }
        if (cmd[i] == '>' && cmd[i + 1] == '>' && cmd[i + 2] == '>') {
            write(2, "Missing name for redirect.", 26);
            return (-1);
        }
    }
    return (0);
}

void replace_cmd_line(shell_t *shell)
{
    replace_alias(shell);
    replace_var(shell);
    replace_repeat(shell);
    replace_quote(shell);
    replace_inhib(shell);
    replace_glob(shell);
}

void main_loop(shell_t *shell)
{
    while (1) {
        if (isatty(0) == 1)
            my_getchar(shell);
        else
            my_get_line(shell);
        if (shell->command_line[0] == 10)
            continue;
        replace_cmd_line(shell);
        if (!shell->error && clean_cmd(shell->command_line) == 0) {
            shell->tree = make_binary_tree(shell->command_line, 0);
            browse_binary_tree(shell, shell->tree);
            clean_binary_tree(shell->tree);
        }
        shell->tree = NULL;
        shell->error = 0;
    }
}
