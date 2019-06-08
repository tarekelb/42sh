/*
** EPITECH PROJECT, 2018
** 42sh.h
** File description:
** header file
*/

#ifndef _42SH_H_
#define _42SH_H_

#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <sys/sysmacros.h>
#include <sys/types.h>
#include <dirent.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <glob.h>
#include <fnmatch.h>
#include <wordexp.h>
#include <termcap.h>
#include <termios.h>
#include "utile.h"
#include "struct.h"
#include "my.h"
#include "env.h"
#include "binary_tree.h"
#include "cmd_exec.h"
#include "alias.h"
#include "init.h"
#include "cd.h"
#include "executor.h"
#include "destroy.h"
#include "replace_var.h"
#include "globbings.h"
#include "my_termcaps.h"

void my_get_line(shell_t *shell);
void main_loop(shell_t *shell);

#endif
