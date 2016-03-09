# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kvignau <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/04 10:52:32 by kvignau           #+#    #+#              #
#    Updated: 2016/01/06 14:56:38 by kvignau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAGS = -Wall -Wextra -Werror

SRC = ft_check.c
SRC += ft_sqrtfillit.c
SRC += ft_registry.c
SRC += ft_actions.c
SRC += ft_lstdbladd.c
SRC += ft_lstdbldel.c
SRC += ft_lstdblnew.c
SRC += ft_resolution.c
SRC += main.c

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C Libft/ all
	gcc -o $(NAME) $(OBJ) -L Libft/ -lft

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	make -C Libft/ clean
	rm -f $(OBJ)

fclean: clean
	make -C Libft/ fclean
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
