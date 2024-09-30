# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:59:33 by lobertho          #+#    #+#              #
#    Updated: 2024/09/30 19:28:07 by lobertho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = $(wildcard *.c)	\
	   $(wildcard */*.c)

OBJS = $(SRCS:.c=.o)

RD_REPLACE = -L /opt/homebrew/Cellar/readline/8.2.13/lib -I /opt/homebrew/Cellar/readline/8.2.13/include

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror $(RD_REPLACE) -lreadline
all: $(NAME)

$(NAME): $(OBJS)
					$(CC) $(FLAGS) $(SRCS) -g -o $(NAME)

clean:
					rm -f $(OBJS)

fclean: clean
					rm -rf minishell.dSYM
					rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
