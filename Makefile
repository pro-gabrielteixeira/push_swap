# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gateixei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/03 21:05:03 by gateixei          #+#    #+#              #
#    Updated: 2022/12/29 20:58:06 by gateixei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
HEADER = push_swap.h
SRC = instructions.c rules_2.c rules.c lst_function.c push_swap.c rules_3.c utils.c main.c ft_atoi.c sorting_small.c sorting_medium.c 
CC = gcc
CFLAGS = -Wextra -Wall -Werror -g -fsanitize=address -o

OBJ = $(SRC: .c=.o)

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(NAME) $(HEADER) $(SRC)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
