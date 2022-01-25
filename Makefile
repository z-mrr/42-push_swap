# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdias-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 12:17:51 by jdias-mo          #+#    #+#              #
#    Updated: 2022/01/25 12:26:57 by jdias-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = \
	push_swap.c do_ops.c list.c list2.c ops.c sort.c sort_utils.c utils.c
BSOURCES = \
	checker.c checker_utils.c get_next_line_utils.c get_next_line.c ops.c \
	list.c list2.c utils.c
OBJECTS = $(SOURCES:.c=.o)
BOBJECTS = $(BSOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: push_swap

bonus: push_swap checker

push_swap: $(OBJECTS)
	gcc -o $@ $(OBJECTS)

checker: $(BOBJECTS)
	gcc -o $@ $(BOBJECTS)

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJECTS) $(BOBJECTS)

fclean: clean
	rm -f push_swap checker

re: fclean all

.PHONY: all bonus clean fclean re
