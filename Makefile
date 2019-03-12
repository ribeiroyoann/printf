# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoann <yoann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/11 16:06:44 by yoribeir          #+#    #+#              #
#    Updated: 2019/03/12 18:24:06 by yoann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

# CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c handlers.c parsers.c utils.c handle_int.c handle_unsigned.c \
handle_char.c handle_pointer.c handle_escape.c handle_string.c handle_wchar.c \
handle_float.c
OBJ = $(SRC:.c=.o)
LIBFT_H = -Ilibft/
LIB_O = $(addprefix ./libft/, *.o)

all: $(NAME)

%.o : %.c
	gcc $(CFLAGS) $(LIBFT_H) -c $?

$(NAME): $(OBJ)
	make -C libft/
	ar rc libftprintf.a $(OBJ) $(LIB_O)

clean:
	make clean -C libft/
	rm -rf $(OBJ)

fclean: clean
	make fclean -C libft/
	rm -rf $(NAME)

re: fclean all