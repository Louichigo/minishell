# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:59:33 by lobertho          #+#    #+#              #
#    Updated: 2023/08/22 17:50:46 by lobertho         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c parse.c ft_split.c utils.c utils2.c free.c exit.c env.c unset.c echo.c pwd.c export.c cd.c path.c signals.c

OBJS = $(SRCS:.c=.o)

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror -lreadline #-L /Users/lobertho/.brew/opt/readline/lib -I .brew/opt/readline/include
all: $(NAME)

$(NAME): $(OBJS)
					$(CC) $(FLAGS) $(SRCS) -g -o $(NAME)

clean:
					rm -f $(OBJS)

fclean: clean
					rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re