NAME = $(shell basename $(CURDIR))

SRCS	= SRCS/minishell.c \
		SRCS/handle/sighandler.c \
		SRCS/parse/check_syntax.c \
		SRCS/parse/expanded_dollar.c \
		SRCS/parse/fill_dollar.c \
		SRCS/parse/fill_pot.c \
		SRCS/parse/fill_red.c \
		SRCS/parse/has_redirect.c \
		SRCS/parse/parse_nodes.c \
		SRCS/parse/treat_redirect.c \
		SRCS/utils/count_strings.c \
		SRCS/utils/free_lines.c \
		SRCS/utils/ft_is_space.c \
		SRCS/utils/ft_split.c \
		SRCS/utils/ft_strjoin.c \
		SRCS/utils/ft_strlen.c \
		SRCS/utils/ft_strncmp.c \
		SRCS/utils/ft_strnstr.c \
		SRCS/utils/get_curr_prog.c \
		SRCS/utils/new_strjoin.c \
		SRCS/builtins/check_builtin.c \
		SRCS/builtins/is_builtin.c \
		SRCS/builtins/my_cd.c \
		SRCS/builtins/my_echo.c \
		SRCS/builtins/my_env.c \
		SRCS/builtins/my_export.c \
		SRCS/builtins/my_pwd.c \
		SRCS/builtins/my_export.c

OBJ		= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -g3 -O3 -fsanitize=address 

LDLIBS = -lreadline

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LDLIBS)

project:
	@mkdir include
	@touch include/$(NAME).h
	@mkdir SRCS
	@touch SRCS/$(NAME).c
	@touch report.txt

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

norm:
	norminette -R CheckForbiddenSourceHeader SRCS/*
	norminette -R CheckDefine INCS/*

re: fclean all

r: all
	./minishell
	