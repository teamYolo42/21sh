# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/22 17:55:04 by asandolo          #+#    #+#              #
#    Updated: 2018/02/21 23:01:13 by asandolo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = clang
CFLAGS = -Wall -Werror -Wextra
INCDIR = includes

SRC = ft_atoi.c ft_bzero.c ft_memcpy.c ft_memset.c \
	  ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
	  ft_putnbr_fd.c ft_strlen.c ft_isupper.c \
	  ft_islower.c ft_isalpha.c ft_isdigit.c \
	  ft_strlen.c ft_isupper.c ft_islower.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	  ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	  ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c \
	  ft_strcmp.c ft_strncmp.c ft_strnew.c ft_strdel.c \
	  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c \
	  ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strcpy.c ft_strncpy.c ft_strdup.c ft_strcat.c \
	  ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strjoin.c ft_strsplit.c ft_isnegativ.c \
	  ft_itoa.c ft_strrev.c ft_strtrim.c ft_strlcat.c \
	  ft_min.c ft_max.c ft_lstnew.c ft_lstdel.c \
	  ft_lstdelone.c ft_lstadd.c ft_lstiter.c ft_lstmap.c \
	  ft_putstr_fd.c ft_putchar_fd.c ft_putofft.c ft_putuint.c \
	  ft_putnstr.c ft_strrchrwa.c ft_strchrwa.c ft_putlong.c \
	  ft_putendl_fd.c ft_nbint.c ft_delchar.c ft_putcolormultistr.c \
	  ft_realloc.c ft_reallocd.c ft_cut.c ft_strcut.c ft_cw.c \
	  ft_putcolormultistr_err.c ft_strgetchartc.c ft_strcmpcuts1.c \
	  epur_str.c ft_strgetstatic.c ft_replacechar.c ft_strdupdup.c \
	  ft_strjoinc.c ft_puttab.c ft_cutspace.c ft_joinsplit.c \
	  ft_specialsplt.c ft_scw.c ft_removefromtab.c freer.c

OBJ = $(SRC:.c=.o)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) -I ./includes/
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re
