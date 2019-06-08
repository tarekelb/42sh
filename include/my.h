/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my personal .h file
*/

#ifndef MY_H_
#define MY_H_

int my_compute_power_rec(int, int);
int my_find_prim_sup(int);
int my_is_prime(int);
int my_isneg(int);
int my_str_isalpha(char const *);
int my_str_isnum(char const *);
int my_str_isprintable(char const *);
int my_str_islower(char const *);
int my_str_isupper(char const *);
char *my_strcapitalize(char *);
char *my_strlowcase(char *);
char *my_strupcase(char *str);
char *my_convert_base(char const *, char const *, char const *);
int my_getnbr_base(char const *, char const *);
int my_getnbr(char const *);
char *my_nbr_to_str(long);
char *my_nbrbase_to_str(long, char *);
int my_nbrlen(long);
int my_nbrlen_base(long, char *);
void my_swap(int *, int *);
char *my_revstr(char *);
char *my_strcat(char *, char const *);
char *my_strncat(char *, char const *, unsigned long);
int my_strcmp(char const *, char const *);
int my_strncmp(char const *, char const *, unsigned long);
char * my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, unsigned long);
char *my_strstr(char *, char const *);
unsigned long my_strlen(char const *);
void my_sort_int_array(int *, int size);
char *my_strdup(char const *);
char **my_str_to_word_array(char const *, char const *);
void my_putchar(char);
void my_putstr(char const *);
int my_put_nbr(int);
int my_putnbr_base(int, char const *);
int my_show_word_array(char const *);
int my_showstr(char const *);
int my_showmem(char const *, int size);
int my_printf(char const *, ...);
void *my_calloc(unsigned long, unsigned long, void *);
void *my_realloc(void *, unsigned long, unsigned long);
void *my_realloc_array(void *, unsigned long, unsigned long, unsigned long);
void my_memcpy(void *, void const *, unsigned long n);
void my_memset(void *, int, unsigned long);
char *my_concat(char *str1, char *str2);
void *my_malloc(size_t byte, size_t size, size_t n);
char *my_itoa_static(long nbr);
void my_ito_str(long nbr, char *str);
unsigned long my_arraylen(void * const *);

#endif
