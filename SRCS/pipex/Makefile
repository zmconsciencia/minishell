NAME = $(shell basename $(CURDIR))

SRCS	= SRCS/pipex.c \
		SRCS/get_path.c \
		SRCS/trim_path.c \
		SRCS/join_path.c \
		SRCS/utils/ft_bzero.c \
		SRCS/utils/ft_calloc.c \
		SRCS/utils/ft_memmove.c \
		SRCS/utils/ft_memset.c \
		SRCS/utils/ft_putstr_fd.c \
		SRCS/utils/ft_split.c \
		SRCS/utils/ft_strjoin.c \
		SRCS/utils/ft_strlen.c \
		SRCS/utils/ft_strnstr.c \
		SRCS/check_access.c \
		SRCS/fill_list.c \
		SRCS/set_fd.c \
		SRCS/free_my_list.c


OBJ		= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -g3 -O3 -fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

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
	./pipex
