# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edalexan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/22 09:15:51 by edalexan          #+#    #+#              #
#    Updated: 2024/09/11 15:28:53 by edalexan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

LIBFT_DIR = -L./libft -lft

SRCS = ./push_verifications.c ./push_sort_some.c ./push_swap.c ./push_utils.c ./push_error_message.c ./push_stack_operations.c ./push_operations.c ./push_operations_2.c ./push_radix_algo.c

OBJS    = $(SRCS:.c=.o)

COMP_LFT = cd ./libft && make

all:	$(NAME)

$(NAME): $(OBJS)
	$(COMP_LFT)
	$(CC) -g $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT_DIR)
	@echo "\033[32msuccess\033[0m!!"

%.o: 	%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	cd ./libft && make clean

fclean: clean
	cd ./libft && make fclean
	rm -f $(NAME)

re:    fclean all

.PHONY: all clean fclean re

