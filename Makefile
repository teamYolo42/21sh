# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcartau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/12 09:02:32 by pcartau           #+#    #+#              #
#    Updated: 2018/02/16 18:40:03 by asandolo         ###   ########.fr        #
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

COMPILING = gcc -Wall -Wextra -Werror -o compile Makefile_srcs/ft_putmultistr.c \
			libft/ft_putchar.c libft/ft_strlen.c Makefile_srcs/gnl.c \
			Makefile_srcs/compile.c

DONE = gcc -Wall -Wextra -Werror -o shell Makefile_srcs/ft_putmultistr.c \
		libft/ft_putchar.c libft/ft_strlen.c Makefile_srcs/gnl.c \
		Makefile_srcs/done.c

NAME = 21sh

SRC = srcs/main.c srcs/process/ft_21sh.c srcs/fnc/ft_puttab.c srcs/buildin/ft_env/ft_env.c \
      srcs/buildin/ft_echo.c srcs/fnc/ft_cutspace.c srcs/fnc/ft_error.c \
      srcs/fnc/ft_erroru.c srcs/fnc/fncenv2.c srcs/buildin/ft_setenv.c \
      srcs/buildin/ft_unsetenv.c srcs/fnc/fncenv.c srcs/buildin/ft_cd.c \
      srcs/process/ft_exec.c srcs/buildin/ft_exit.c srcs/fnc/cdfnc.c \
      srcs/buildin/ft_cd2.c srcs/fnc/fncecho.c srcs/signal/sig_kill.c \
      srcs/fnc/ft_prompt.c srcs/fnc/ft_starting.c srcs/fnc/opts/envopts.c \
      srcs/fnc/ft_checkcmd.c srcs/fnc/ft_joinsplit.c srcs/buildin/ft_env/ft_env2.c


OBJ = $(SRC:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
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
