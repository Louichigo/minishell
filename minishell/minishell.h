/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:19 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/22 19:21:22 by lobertho         ###   ########.fr       */
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
# include <stdbool.h>
# include <readline/readline.h>
# include <readline/history.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

int		globalv;

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
	struct s_env *previous;
}	t_env;

void	ft_exit(t_env *env);
void	ft_echo(t_data *s, char *str, int echon);
void	ft_lexer(t_data *s, t_env *env);
void	if_dollar(t_env *env, char *str);
void	exec_cmd(char **cmd, char **envp);
void	ft_free(char **str);
void	ft_freeenv(t_env *env);
void	ft_pwd(void);
void	ft_env(t_env *env);
void	ft_export(t_env *env, char *name, char *value);
void	ft_unset(t_env *env, char *name);
void	ft_exit(t_env *env);
void	ft_cd(t_env *env, char *str);
void	signalsinit(void);
void	ft_putstr_fd(char *s, int fd);

t_env	*init_env(char **envp);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);
char	**get_all_path();
char *get_right_path(char *cmd);
char	*ft_strdup(const char *s1);
char 	*ft_splitname(char *str);
char 	*ft_splitvalue(char *str);
char	**ft_split(char const *s, char c);

int	ft_atoi(const char *str);
int	ft_strcmp(char *s1, char *s2);

#endif 