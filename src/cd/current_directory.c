/*
** EPITECH PROJECT, 2019
** current_directory
** File description:
** directory
*/

#include "ftsh.h"

void manage_directory(shell_t *shell)
{
    char **tmp = my_str_to_word_array(shell->command_line, "\n \t");

        if (!strcmp(tmp[0], "cd"))
            classic_cd(tmp, shell);
    free_tab(tmp);
}

void classic_cd(char **tmp, shell_t *shell)
{
    static int a = 0;
    char buff[CMD_SIZE] = {0};

    if (error_file(tmp) == -1)
        return;
    else if (tmp[1] && strcmp(tmp[1], "-") && \
    strcmp(tmp[1], "home") && !tmp[2]) {
        getcwd(buff, 255);
        if (chdir(tmp[1]) == -1) {
            printf("%s: No such file or directory.\n", tmp[1]);
            shell->return_status = 1;
            return;
        }
        ++a;
        set_list_env(shell, "OLDPWD", buff);
        set_list_env(shell, "PWD", getcwd(buff, 255));
    }
    home_cd(tmp, shell, a);
    old_cd(tmp, shell, a);
    shell->return_status = 0;
}

void home_cd(char **tmp, shell_t *shell, int a)
{
    char buff[CMD_SIZE] = {0};

    if ((!tmp[1]) || (strcmp(tmp[1], "-") && \
    !strcmp(tmp[1], "home") && !tmp[2])) {
        ++a;
        getcwd(buff, 255);
        if (chdir(get_data_env(shell->env_list, "HOME")) == -1 && !tmp[1]) {
            printf("%s: No home directory.\n", tmp[0]);
            shell->return_status = 1;
            return;
        } else if (chdir(get_data_env(shell->env_list, "HOME")) == -1) {
            printf("%s: No such file or directory.\n", tmp[1]);
            shell->return_status = 1;
            return;
        }
        set_list_env(shell, "OLDPWD", buff);
        set_list_env(shell, "PWD", getcwd(buff, 255));
    }
}

void old_cd(char **tmp, shell_t *shell, int a)
{
    char buff[255] = {0};

    if (tmp[1] && !strcmp(tmp[1], "-") && !tmp[2]) {
        getcwd(buff, 255);
        if (a == 0) {
            printf(": No such file or directory.\n");
            shell->return_status = 1;
            return;
        } else if (chdir(get_data_env(shell->env_list, "OLDPWD")) == -1) {
            printf("%s: No such file or directory.\n", tmp[1]);
            shell->return_status = 1;
            return;
        }
        set_list_env(shell, "OLDPWD", buff);
        set_list_env(shell, "PWD", getcwd(buff, 255));
    }
}
