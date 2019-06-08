##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## 42sh makefile
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

SRCS	= ./src/alias/add_alias.c \
	./src/alias/alias_manager.c \
	./src/alias/remove_alias.c \
	./src/alias/replace_alias.c \
	./src/binary/browse_binary_tree.c \
	./src/binary/clean_binary_tree.c \
	./src/binary/make_binary_tree.c \
	./src/binary/pipe_manag.c \
	./src/binary/redir_double_left.c \
	./src/binary/redir_double_right.c \
	./src/binary/redir_simple_left.c \
	./src/binary/redir_simple_right.c \
	./src/binary/double_amp.c \
	./src/binary/double_pipe.c \
	./src/binary/set_err.c \
	./src/cd/current_directory.c \
	./src/cd/utils_directory.c \
	./src/cmd_exec/cmd_executor.c \
	./src/cmd_exec/cmd_executor_utile_function.c \
	./src/cmd_exec/cmd_manager.c \
	./src/destroy/destroy_struct.c \
	./src/env/create_env.c \
	./src/env/destroy_env.c \
	./src/env/display_env.c \
	./src/env/emergency_env.c \
	./src/env/manage_env.c \
	./src/env/set_env.c \
	./src/env/unset_env.c \
	./src/env/error_env.c	\
	./src/executor/builtin_executor.c \
	./src/executor/builtin_executor_bis.c \
	./src/executor/builtin_executor_bis2.c \
	./src/executor/manage_error.c \
	./src/globbings/glob.c	\
	./src/inhibitor/inhib.c \
	./src/inhibitor/repeat.c \
	./src/inhibitor/where.c \
	./src/inhibitor/quote.c \
	./src/scripting/inhibitor_int_point.c \
	./src/variables/set_forking.c \
	./src/variables/unset_forking.c \
	./src/variables/utils_var.c \
	./src/variables/var_env.c \
	./src/variables/set_unset_var.c	\
	./src/variables/set_var.c	\
	./src/init/init_struct.c \
	./src/termcaps_history/arrow.c \
	./src/termcaps_history/history.c \
	./src/termcaps_history/my_cursor.c \
	./src/termcaps_history/my_get.c \
	./src/termcaps_history/stack.c \
	./src/termcaps_history/term_test2.c \
	./src/termcaps_history/move.c \
	./src/termcaps_history/history_finder.c \
	./src/main.c \
	./src/main_loop.c \

OBJS	= $(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra

LIBMY = -L ./lib/ -lmy

MYLIB_FOLDER = ./lib/my/

all: $(NAME)

$(NAME): mylib $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) $(LIBMY)

mylib:
	make -C lib/my/

cleanall:
	$(RM) $(OBJS)
	make clean -C $(MYLIB_FOLDER)

fcleanall: clean
	$(RM) $(NAME)
	make fclean -C $(MYLIB_FOLDER)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
