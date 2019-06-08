/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** main
*/

#include "ftsh.h"

int main(UNUSED int ac, UNUSED char **av, char **env)
{
    shell_t shell = {0};

    init_shell(&shell, env);
    main_loop(&shell);
    destroy_struct(&shell);
    return (0);
}
