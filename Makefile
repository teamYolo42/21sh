# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcartau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 09:02:32 by pcartau           #+#    #+#              #
#    Updated: 2018/01/30 15:36:58 by pcartau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLORS
RESET=\033[0m
DARK=\033[132m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m
BOLDBLACK=\033[1m\033[30m
BOLDRED=\033[1m\033[31m
BOLDWHITE=\033[1m\033[37m

COMPILING = gcc -Wall -Wextra -Werror -o compile libft/ft_putmultistr.c \
			libft/ft_putchar.c libft/ft_strlen.c Makefile_srcs/gnl.c \
			Makefile_srcs/compile.c

DONE = gcc -Wall -Wextra -Werror -o shell libft/ft_putmultistr.c \
		libft/ft_putchar.c libft/ft_strlen.c Makefile_srcs/gnl.c \
		Makefile_srcs/done.c

NAME = minishell

SRC = srcs/ft_92.c srcs/ft_cd.c srcs/ft_do_work_bitch.c srcs/ft_echo.c \
	srcs/ft_env.c srcs/ft_error.c srcs/ft_execute.c srcs/ft_exit.c \
	srcs/ft_getenv.c srcs/ft_setenv.c srcs/ft_unsetenv.c srcs/main.c


OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc

.PHONY: clean fclean re re-bis
.SILENT :

all : $(NAME)

$(NAME): $(OBJ)
	$(COMPILING)
	rm -f Makefile_srcs/gnl.o Makefile_srcs/main1.o
	./compile
	$(DONE)
	make -C libft/
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I libft/ -L libft/ -lft
	rm -f Makefile_srcs/gnl.o Makefile_srcs/main2.o
	./shell
	rm -f compile shell

clean:
	make -C libft/ clean
	rm -f $(OBJ)

fclean : clean
	make -C libft/ clean
	rm -f $(NAME)

re: fclean all

re-bis:
	rm -f $(OBJ)
	rm -f $(NAME)
	$(CC) $(CFLAGS) $(SRC) -o $(NAME) -I libft/ -L libft/ -lft
