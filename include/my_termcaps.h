/*
** EPITECH PROJECT, 2019
** file
** File description:
** terminal capability
*/

#ifndef ARROW_H_
#define ARROW_H_

#define cursorforward(x) printf("\033[%dC", (x))
#define cursorbackward(x) printf("\033[%dD", (x))

#define KEY_ESCAPE  27
#define KEY_ENTER   0x000a
#define KEY_UP      0x0105
#define KEY_DOWN    0x0106
#define KEY_LEFT    0x0107
#define KEY_RIGHT   0x0108
#define KEY_DEL     127
#define ENDOF       4

int my_getch(void);
int my_kbhit(void);
int my_getchararrow(void);
int my_getchar2(void);
int find_arrow(int c);
void my_getchararrows(int c);
char *fill(char *str);
void create_vec(vector_t *vector);
char *my_realloc_str(char *str, int a);
void vec_realloc(vector_t *vector);
void add_vec(vector_t *vector, int pos, char c);
void remove_vec(vector_t *vector, int pos);
void actualcursor(vector_t *vector);
void my_freestr(vector_t *vector);
char **add_history(char *func, char **str);
history_t *create_history(void);
char **my_realloc2(char **str, int a);
void my_getchar(shell_t *shell);
void free_my_vec(shell_t *shell);
void destroy_history(shell_t *shell);

void move_up(shell_t *shell);
void my_tty(void);
void move_down(shell_t *shell);
int verif_return(char *str);
void getchar_n(shell_t *shell, int c);
void history_move(shell_t *shell, int c);
void my_getprint(vector_t *vector, int c);
void check_eof(void);
void getchar_cond(shell_t *shell, int c);
int str_finder(char *str, char *history);
int history_find(char *str, char **history, int pos);

void ini_get_char(shell_t *shell);
#endif
