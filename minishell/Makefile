# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 16:59:33 by lobertho          #+#    #+#              #
#    Updated: 2023/08/31 12:01:49 by cgross           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c parse.c ft_split.c utils.c utils2.c free.c exit.c env.c unset.c echo.c pwd.c export.c cd.c path.c signals.c tokenizer.c tokenizer_utils.c get_quote.c lists.c redirection.c get.c heredoc.c exec.c builtin.c utils3.c ft_itoa.c rep_dollar.c

OBJS = $(SRCS:.c=.o)

NAME = minishell

CC = gcc

FLAGS = -Wall -Wextra -Werror -lreadline -L/Users/lobertho/.brew/opt/readline/lib -I/Users/lobertho/.brew/opt/readline/include
all: $(NAME)

$(NAME): $(OBJS)
					$(CC) $(FLAGS) $(SRCS) -g -o $(NAME)

clean:
					rm -f $(OBJS)

fclean: clean
					rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
