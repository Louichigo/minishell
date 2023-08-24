/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:19 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/23 18:03:44 by lobertho         ###   ########.fr       */
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

typedef struct s_env
{
	char	*name;
	char	*value;
	struct s_env *next;
	struct s_env *previous;
}	t_env;

typedef struct s_token
{
	int					type;
	int					flag;
	int					error;
	int					flag_env[100];
	int					syntax;
	int					i;
	int					pos;
	int					env_len;
	int					file_type;
	int					fdwrite;
	int					fdread;
	char				*end_of_file;
	char				*cmd;
	char				**arg;
	char				**g_env;
	char				**arg_all;
	struct s_token		*next;
}				t_token;

enum e_token {
	COMMAND = 1,
	ARG = 2,
	PIPE = 3,
	R_LEFT = 4,
	R_RIGHT = 5,
	RR_LEFT = 6,
	RR_RIGHT = 7,
};

void	ft_exit(t_env *env);
void	ft_echo(char *str, int echon);
void	if_dollar(t_env *env, char *str);
void	exec_cmd(char **cmd, char **envp);
void	ft_free(char **str);
void	ft_freeenv(t_env *env);
void	ft_pwd(void);
void	ft_env(t_env *env);
void	ft_export(t_env *env, char *name, char *value);
void	ft_unset(t_env **env, char *name);
void	ft_exit(t_env *env);
void	ft_cd(t_env *env, char *str);
void	signalsinit(void);
void	ft_putstr_fd(char *s, int fd);
void	parser(char *input, t_env *env);
void	initok(t_token *new, int index);
void	space_index(t_token *new, char *input);
void	get_cmd(t_token *new, char *input);
void	get_arg(t_token *new, char *input);
void	get_squote_cmd(t_token *new, char *input);
void	get_dquote_cmd(t_token *new, char *input);
void	get_squote(t_token *new, char *input);
void	get_dquote(t_token *new, char *input);
void	get_word(t_token *new, char *input);
void	add_last(t_token **list, t_token *new);
void	print_list(t_token *list);

bool	isdeli(char c, char flag);
bool	is_aspace(char c);
bool	is_redi(char c);


t_env	*init_env(char **envp);

t_token	*get_last(t_token *list);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);
char	**get_all_path();
char *get_right_path(char *cmd);
char	*ft_strdup(const char *s1);
char 	*ft_splitname(char *str);
char 	*ft_splitvalue(char *str);
char	**ft_split(char const *s, char c);

int	ft_strcmp(char *s1, char *s2);
int	tokenizer(t_token **tok, char *input, int index);
int	word_len(char *input, int i);
int	mystrcspn(char *s, char *reject, int i);
int	env_handler(t_token *new, char *input, int j);

#endif 