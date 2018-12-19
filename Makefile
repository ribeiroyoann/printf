# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoann <yoann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/19 12:25:14 by yoribeir          #+#    #+#              #
#    Updated: 2018/12/19 17:43:40 by yoann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf
INCLUDES = includes
LIBS = libft
LIB = ft
FLAGS = -Wall -Werror -Wextra
SRCS = ft_printf.c handlers.c parsers.c utils.c handle_int.c handle_octal.c \
handle_char.c
SRCSREP = srcs
OBJS = $(SRCS:.c=.o)

.SILENT:

all: $(NAME)

%.o: $(SRCSREP)/%.c
	gcc $(FLAGS) -I$(INCLUDES) -c $^

$(NAME): $(OBJS)
	@make -C libft
	gcc $(FLAGS) -I$(INCLUDES) $^ -L$(LIBS) -l$(LIB) -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft
fclean: clean
	make fclean -C libft
	rm -f $(NAME)
re: fclean all