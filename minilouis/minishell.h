/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:19 by lobertho          #+#    #+#             */
/*   Updated: 2023/05/17 16:21:29 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

# define UP	126
# define DOWN 125
# define HISTSIZE 500

typedef struct s_data
{
	int				wordscount;
	char			*line;
	char			**lexer;
	char			*history[HISTSIZE];
	unsigned int	history_count;
	unsigned int	ith;
		
}	t_data;

void	ft_lexer(t_data *s);
void	add_command_to_history(t_data *s);
void	exec_cmd(char **cmd);
void	ft_free(char **str);

char	*ft_strdup(const char *s1);
char	**ft_split(char const *s, char c);

int	ft_atoi(const char *str);

#endif 