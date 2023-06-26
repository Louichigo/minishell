/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:19 by lobertho          #+#    #+#             */
/*   Updated: 2023/06/26 20:50:33 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

typedef struct s_data
{
	int				wordscount;
	char			*line;
	char			**lexer;
		
}	t_data;

typedef struct s_env
{
	char	*name;
	char	*value;
	struct s_env *next;
}	t_env;

void	ft_lexer(t_data *s);
void	if_dollar(t_env *env, char *str);
void	exec_cmd(char **cmd);
void	ft_free(char **str);
void	ft_pwd(void);
void	ft_env(t_env *env);
void	ft_export(t_env *env, char const *name, char const *value);
void	ft_unset(t_env *env, char const *name);

t_env	*init_env(char **envp);

char	*ft_strdup(const char *s1);
char 	*ft_splitname(char *str);
char 	*ft_splitvalue(char *str);
char	**ft_split(char const *s, char c);

int	ft_atoi(const char *str);
int	ft_strcmp(char *s1, char *s2);

#endif 