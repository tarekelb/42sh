/*
** EPITECH PROJECT, 2019
** cmd_executor.c
** File description:
** manage execution of commande
*/

#include "ftsh.h"

int exec_cmd_child(shell_t *shell, tree_t *tree, char const *cmd, int fd[])
{
    if (fd[0] > 1 || fd[1] > 1) {
        if (fd[0] != 0)
            dup2(fd[0], 0);
        if (fd[1] != 1)
            dup2(fd[1], 1);
        if (fd[2] != 0)
            close(fd[2]);
        if (fd[3] != 1)
            close(fd[3]);
    }
    execve(cmd, tree->cmd, shell->env);
    exit(0);
    return (0);
}

int exec_cmd_father(shell_t *shell, int pid, int fd[])
{
    int sig = -1;

    if (fd[0] > 1 || fd[1] > 1) {
        if (fd[2] != 0)
            close(fd[2]);
        if (fd[3] != 1)
            close(fd[3]);
    }
    waitpid(pid, &sig, 0);
    if (sig_catch(sig) || sig)
        set_err(shell, -1);
    if (fd[1] != 1)
        close(fd[1]);
    if (fd[0] != 0)
        close(fd[0]);
    return (shell->error);
}

int exec_cmd(shell_t *shell, tree_t *tree, char const *cmd)
{
    int pid = fork();

    if (pid == -1) {
        set_err(shell, 3);
        return (-2);
    }
    if (!pid) {
        exec_cmd_child(shell, tree, cmd, tree->fd);
        exit(shell->error ? 512 : 0);
    } else {
        return (exec_cmd_father(shell, pid, tree->fd));
    }
    return (0);
}

void cmd_executor_bis(shell_t *shell, tree_t *tree)
{
    char tmp[256];
    char **path = find_cmd_path(shell);

    if (!path)
        return (set_err(shell, -1));
    for (int i = 0; path[i]; ++i) {
        memset(tmp, 0, 256);
        strcat(strcat(strcat(tmp, path[i]), "/"), *tree->cmd);
        if (access(tmp, F_OK))
            continue;
        if (exec_cmd(shell, tree, tmp) == -1) {
            clean_path_array(path);
            return (set_err(shell, -1));
        } else
            return (clean_path_array(path));
    }
    set_err(shell, -1);
    fprintf(stderr, "%s: Command not found.\n", *tree->cmd);
    clean_path_array(path);
}

void cmd_executor(shell_t *shell, tree_t *tree)
{
    if (access(*tree->cmd, X_OK) != 0) {
        if (strlen(shell->path) == 0) {
            fprintf(stderr, "%s: Command not found.\n", *tree->cmd);
            return (set_err(shell, -1));
        }
        cmd_executor_bis(shell, tree);
        return;
    }
    if (exec_cmd(shell, tree, *tree->cmd) == -1)
        return (set_err(shell, -1));
}
