/*
** EPITECH PROJECT, 2019
** cmd_executor_utile_function.c
** File description:
** manage execution of commande
*/

#include "ftsh.h"

int sig_catch(int sig)
{
    if (WIFSIGNALED(sig)) {
        if (WTERMSIG(sig) == SIGSEGV)
            fprintf(stderr, "Segmentation fault");
        if (WTERMSIG(sig) == SIGFPE)
            fprintf(stderr, "Floating exception");
        if (WTERMSIG(sig) == SIGABRT)
            fprintf(stderr, "Abort");
        if (WCOREDUMP(sig))
            fprintf(stderr, " (core dumped)");
        fprintf(stderr, "\n");
        return (1);
    }
    return (0);
}

char **find_cmd_path(shell_t *shell)
{
    char *tmp = NULL;
    int i = 0;

    for (; shell->env[i]; ++i)
        if (!strncmp(shell->env[i], "PATH=", 5)) {
            tmp = shell->env[i];
            return (my_str_to_word_array(tmp + 5, ":"));
    }
    if (!shell->env[i])
        return (my_str_to_word_array(shell->path, ":"));
    return (NULL);
}

void clean_path_array(char **path)
{
    if (path) {
        for (int i = 0;path[i]; ++i)
            free(path[i]);
        free(path);
    }
}
