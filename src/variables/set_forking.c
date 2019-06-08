/*
** EPITECH PROJECT, 2019
** set_forking.c
** File description:
** set local var
*/

#include "ftsh.h"

void exec_cmd_child_set(shell_t *shell, tree_t *tree)
{
    int ctr_err = -1;

    if (tree->fd[0] != 0)
        dup2(tree->fd[0], 0);
    if (tree->fd[1] != 1)
        dup2(tree->fd[1], 1);
    if (tree->fd[2] != 0)
        close(tree->fd[2]);
    if (tree->fd[3] != 1)
        close(tree->fd[3]);
    for (int a = 0; tree->cmd[a]; a += 1)
        if (set_var(shell, tree->cmd, a) == -1) {
            ctr_err = -1;
            break;
        }
    exit(ctr_err == -1 ? 512 : 0);
}

void exec_cmd_father_set(shell_t *shell, tree_t *tree, int pid, int fd[])
{
    int sig = -1;

    if (tree->fd[2] != 0)
        close(tree->fd[2]);
    if (tree->fd[3] != 1)
        close(tree->fd[3]);
    waitpid(pid, &sig, 0);
    if (sig_catch(sig) || sig) {
        set_err(shell, -1);
        return;
    }
    if ((fd[0] != 0 || fd[1] != 1) && tree->fd[1] != 1)
        close(tree->fd[1]);
    if ((fd[0] != 0 && fd[1] != 1) && tree->fd[0] != 0)
        close(tree->fd[0]);
    return;
}

void set_var_all(shell_t *shell, tree_t *tree)
{
    int pid = -1;

    if (tree->cmd == NULL)
        return;
    if (tree->fd[0] == 0 && tree->fd[1] == 1) {
        return (set_var_all_exec(shell, tree));
    }
    pid = fork();
    if (pid == -1) {
        set_err(shell, 3);
        return;
    }
    if (!pid) {
        return (exec_cmd_child_set(shell, tree));
    } else {
        return (exec_cmd_father_set(shell, tree, pid, tree->fd));
    }
    return;
}
