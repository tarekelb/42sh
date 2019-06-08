/*
** EPITECH PROJECT, 2019
** var_env
** File description:
** var_env
*/

#include "ftsh.h"

int destroy_all_var(char *var_env, char *var, char *dest, shell_t *shell)
{
    if (!var_env && !var) {
        printf("%s: Undefined variable.\n", dest);
        free(dest);
        free(var_env);
        free(var);
        shell->error = -1;
        return (-1);
    }
    return (0);
}

void cpy_var(shell_t *shell, char *tmp, char *var_env)
{
    int a = offset_var(shell);
    int b = 0;
    int len = strlen(shell->command_line);
    int c = offset_var(shell) + (strlen_var(shell->command_line, \
    offset_var(shell)));

    shell->command_line = realloc(shell->command_line, CMD_SIZE + 4);
    for (; var_env[b]; b += 1, a += 1)
        shell->command_line[a] = var_env[b];
    for (; c < len && tmp[c]; c += 1, a += 1)
        shell->command_line[a] = tmp[c];
    shell->command_line[a] = 0;
}

void replace_var(shell_t *shell)
{
    char *dest = NULL;
    char *var_env = NULL;
    char *var = NULL;
    int a = a = offset_var(shell);
    char *tmp = calloc(CMD_SIZE, 1);

    tmp = strcpy(tmp, shell->command_line);
    for (; is_var(shell->command_line);) {
        dest = strcpy_var(dest, shell->command_line, a + 1, \
        strlen_var(shell->command_line, offset_var(shell)) - 1);
        var_env = get_data_env(shell->env_list, dest);
        var = get_data_env(shell->var_list, dest);
        if (destroy_all_var(var_env, var, dest, shell) == -1) {
            free(tmp);
            return;
        }
        cpy_var(shell, tmp, (var_env) ? var_env : var);
        free(dest);
    }
    free(tmp);
}
