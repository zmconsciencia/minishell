NAME = $(shell basename $(CURDIR))

SRCS	= SRCS/minishell.c \
		SRCS/execute/execute.c \
		SRCS/execute/finish_program.c \
		SRCS/execute/clear_last.c \
		SRCS/execute/treat_heredoc.c \
		SRCS/handle/sighandler.c \
		SRCS/parse/check_syntax.c \
		SRCS/parse/expand_now.c \
		SRCS/parse/expanded_dollar.c \
		SRCS/parse/fill_pot.c \
		SRCS/parse/fill_red.c \
		SRCS/parse/parse_nodes.c \
		SRCS/parse/treat_redirect.c \
		SRCS/parse/treat_and_replace.c \
		SRCS/parse/treat_quotes.c \
		SRCS/utils/builtin_utils.c \
		SRCS/utils/count_strings.c \
		SRCS/utils/free_lines.c \
		SRCS/utils/ft_atoi.c \
		SRCS/utils/ft_is_space.c \
		SRCS/utils/ft_putstr_fd.c \
		SRCS/utils/ft_split.c \
		SRCS/utils/ft_strchr.c \
		SRCS/utils/ft_strjoin.c \
		SRCS/utils/ft_strlcpy.c \
		SRCS/utils/ft_strlen.c \
		SRCS/utils/ft_strncmp.c \
		SRCS/utils/ft_strnstr.c \
		SRCS/utils/is_alpha_num.c \
		SRCS/utils/lst_utils.c \
		SRCS/utils/new_strjoin.c \
		SRCS/utils/red_utils.c \
		SRCS/utils/ft_itoa.c \
		SRCS/builtins/check_builtin.c \
		SRCS/builtins/do_builtin.c \
		SRCS/builtins/is_builtin.c \
		SRCS/builtins/my_cd.c \
		SRCS/builtins/my_echo.c \
		SRCS/builtins/my_env.c \
		SRCS/builtins/my_export_utils.c \
		SRCS/builtins/my_export.c \
		SRCS/builtins/my_exit.c \
		SRCS/builtins/my_pwd.c \
		SRCS/builtins/my_unset.c \
		SRCS/gnl/get_next_line.c \
		SRCS/gnl/get_next_line_utils.c \
		SRCS/pipex/pipex.c \
		SRCS/pipex/get_path.c \
		SRCS/pipex/trim_path.c \
		SRCS/pipex/join_path.c \
		SRCS/pipex/check_access.c

OBJ		= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Wextra -g3  -g -Werror #-fsanitize=address

LDLIBS = -lreadline

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra  -g3 -c $< -o $@

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