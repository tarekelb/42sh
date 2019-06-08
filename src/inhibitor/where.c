/*
** EPITECH PROJECT, 2019
** where.c
** File description:
** where
*/

#include "ftsh.h"

void where(shell_t *shell, char *cmd)
{
    static char tmp[CMD_SIZE];
    char **path = NULL;
    int index = 0;

    if (!cmd)
        return;
    path = find_cmd_path(shell);
    for (; path[index]; index++) {
        memset(tmp, 0, sizeof(tmp));
        sprintf(tmp, "%s/%s", path[index], cmd);
        if (access(tmp, F_OK) == 0)
            break;
    }
    if (access(tmp, F_OK) == 0)
        printf("%s\n", tmp);
    else {
        fprintf(stderr, "%s: Command not found.\n", cmd);
        shell->return_status = 1;
    }
}
