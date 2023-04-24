NAME = $(shell basename $(CURDIR))

SRCS	= SRCS/minishell.c \
		SRCS/handle/sighandler.c \
		SRCS/handle/sighandler2.c \
		SRCS/utils/ft_split.c

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
	