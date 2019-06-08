/*
** EPITECH PROJECT, 2018
** binary_tree.h
** File description:
** header file for binary_tree
*/

#ifndef _BINARY_TREE_H_
#define _BINARY_TREE_H_

tree_t *make_binary_tree(char const *, int);
void browse_binary_tree(shell_t *, tree_t *);
void clean_binary_tree(tree_t *);
void double_pipe(shell_t *, tree_t *);
void double_amp(shell_t *, tree_t *);
void redir_double_left(shell_t *, tree_t *);
void redir_double_right(shell_t *, tree_t *);
void redir_simple_left(shell_t *, tree_t *);
void redir_simple_right(shell_t *, tree_t *);
void pipe_manager(shell_t *, tree_t *);
void set_err(shell_t *, int);

#endif
