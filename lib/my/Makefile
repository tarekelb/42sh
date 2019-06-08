##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

NAME	= libmy.a

CC	= gcc

RM	= rm -f

MV  = mv

AR =	ar rc

SRCS	=	./my_arraylen.c	\
	  ./my_calloc.c \
	  ./my_compute_power_rec.c \
	  ./my_compute_square_root.c \
	  ./my_convert_base.c \
	  ./my_find_prime_sup.c \
	  ./my_getnbr.c \
	  ./my_getnbr_base.c \
	  ./my_nbrlen.c \
	  ./my_is_prime.c \
	  ./my_isneg.c \
	  ./my_memcpy.c \
	  ./my_memset.c \
	  ./my_nbr_to_str.c \
	  ./my_put_nbr.c \
	  ./my_putchar.c \
	  ./my_putnbr_base.c \
	  ./my_putstr.c \
	  ./my_realloc.c \
	  ./my_revstr.c \
	  ./my_show_word_array.c \
	  ./my_showmem.c \
	  ./my_showstr.c \
	  ./my_sort_int_array.c \
	  ./my_str_isalpha.c \
	  ./my_str_islower.c \
	  ./my_str_isnum.c \
	  ./my_str_isprintable.c \
	  ./my_str_isupper.c \
	  ./my_str_to_word_array.c \
	  ./my_strcapitalize.c \
	  ./my_strcat.c \
	  ./my_strcmp.c \
	  ./my_strcpy.c \
	  ./my_strdup.c \
	  ./my_strlen.c \
	  ./my_strlowcase.c \
	  ./my_strncat.c \
	  ./my_strncmp.c \
	  ./my_strncpy.c \
	  ./my_strstr.c \
	  ./my_strupcase.c \
	  ./my_swap.c \
	  ./my_malloc.c \

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
	$(MV) $(NAME) ../

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
