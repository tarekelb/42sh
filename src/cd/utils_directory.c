/*
** EPITECH PROJECT, 2019
** current_directory
** File description:
** utils_directory
*/

#include "ftsh.h"

int error_file(char **tmp)
{
    struct stat he;

    if (tmp[1] != NULL && strcmp(tmp[1], "-")) {
        stat(tmp[1], &he);
        if (strcmp(tmp[1], "home") & (he.st_mode & __S_IFMT) && \
        (he.st_mode & __S_IFREG)) {
            printf("%s: Not a directory.\n", tmp[1]);
            return (-1);
        }
    }
    return (0);
}

void free_tab(char **tab)
{
    for (int a = 0; tab[a]; a += 1)
        free(tab[a]);
    free(tab);
}