/*
** EPITECH PROJECT, 2018
** emergency_env.c
** File description:
** emergency env
*/

#include "ftsh.h"

char **emergency_env(void)
{
    static char cwd[255];
    static char *env[12] = {"HOSTTYPE=x86_64-linux", "VENDOR=unknown", \
    "OSTYPE=linux", "MACHTYPE=x86_64", "SHLVL=1", "PWD=/", "LOGNAME=unknown", \
    "USER=unknown", "GROUP=unknown", "HOST=unknown", \
    "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:" \
    "/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin", NULL};

    getcwd(cwd + 4, 251);
    strcat(cwd, "PWD=");
    env[5] = cwd;
    return (env);
}
