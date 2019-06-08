/*
** EPITECH PROJECT, 2019
** struct.h
** File description:
** virtual machine's structs
*/

#ifndef STRUCT_H_
#define STRUCT_H_

typedef struct history_s {
    char **str;
    unsigned pos;
} history_t;

typedef struct vector_s {
    char *test;
    int size;
    int content;
    int pos;
} vector_t;

typedef struct list_s
{
    char id[CMD_SIZE / 2];
    char data[CMD_SIZE];
    struct list_s *next;
    struct list_s *prev;
} list_t;

typedef struct tree_s
{
    int fd[4];
    char **cmd;
    char const *parce;
    struct tree_s *right;
    struct tree_s *left;
} tree_t;

typedef struct alias_s
{
    char cmd[255];
    char new[CMD_SIZE];
} alias_t;

typedef struct shell_s
{
    char **env;
    char path[CMD_SIZE];
    char *home;
    list_t *env_list;
    list_t *var_list;
    char *command_path;
    char *command_line;
    vector_t *vector;
    char **command_history;
    unsigned int history_len;
    unsigned int history_pos;
    alias_t *command_alias;
    unsigned int alias_len;
    tree_t *tree;
    int is_child;
    char error;
    int return_status;
} shell_t;

#endif
