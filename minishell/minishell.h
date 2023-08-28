/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:19 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/28 23:05:32 by lobertho         ###   ########.fr       */
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
# include <fcntl.h>
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
	int					count;
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
	char				*exportname;
	char				*exportvalue;
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
void	exec_cmd(char **cmd, char **envp);
void	ft_free(char **str);
void	free_token(t_token **token);
void	free_double(t_token *token);
void	ft_freeenv(t_env *env);
void	ft_pwd(void);
void	ft_env(t_env *env, t_token *s);
void	ft_export(t_env *env, char *name, char *value);
void	ft_unset(t_env **env, char *name);
void	ft_exit(t_env *env);
void	ft_cd(t_env *env, char *str);
void	signalsinit(void);
void	ft_putstr_fd(char *s, int fd);
void	add_tab(t_token *token, int new);
void	exec_builtin(t_token *s, t_env *env);
void	ft_export_parse(t_token *s, t_env *env);
void	ft_unset_parse(t_token *s, t_env *env);
void	ft_cd_parse(t_token *s, t_env *env);
void	ft_echo_parse(t_token *s, t_env *env);
void	execution(t_token *s, t_env *env);

t_env	*init_env(char **envp);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);
char	**get_all_path();
char	 *get_right_path(char *cmd);
char	*ft_strdup(const char *s1);
char 	*ft_splitname(char *str);
char 	*ft_splitvalue(char *str);
char	**ft_split(char const *s, char c);
char	*ft_dechar(char **str);
char	*ft_echon(char **str, int i);
char	*if_dollar(t_env *env, char *str);
char	*ft_finddollar(t_token *s, t_env *env, char *str);
char	*ft_putdollar(t_env *env, char *str, int len);
char *ft_jenpeuxplus(t_token *s, char *str, char *dollar);

int	is_builtin(t_token *s);
int	ft_fulllen(char **str, int i);
int	ft_strcmp(char *s1, char *s2);

//tokenizer.c
int				sequencer(t_token **head, char *input, t_env *envi, int index);
void			get_cmd(t_token *new, char *input);
void			get_redirection(t_token *new, char *input);
void			get_arg(t_token *new, char *input);
int				word_len(char *input, int i);

//tokenizer_utils.c
int				isredi(char c);
int				isdeli(char c, char flag);
int				ft_isaspace(char c);
void			space_index(t_token *new, char *input);
int				checkquotes(char *input, char quote, int i);
void			initialisation(t_token	*head);

//linked_list.c
void			add_token(t_token **head, char **command);
void			add_last(t_token **head, t_token *new);
t_token			*get_last(t_token *head);
void			print_list(t_token *head);

//get.c

void			get_word(t_token *new, char *input);
void			get_squote(t_token *new, char *input);
void			get_dquote(t_token *new, char *input);
int				mystrcspn(char *s, char *reject, int i);
int				env_handler(t_token *new, char *input, int j);

//get_quote.c

void			get_squote_cmd(t_token *new, char *input);
void			get_dquote_cmd(t_token *new, char *input);

//heredoc.c
void			heredoc(t_token *new, char *input);
int				iscontained(char *here, char *eof);
int				isword(char *here, char *eof, int index);

//redirection.c

void			r_left(t_token *new, char *input);
void			rr_left(t_token *new, char *input);
void			r_right(t_token *new, char *input);
void			rr_right(t_token *new, char *input);
char			*get_filename(t_token *new, char *input);

//parser.c

bool			check_quotes(char *input);
void			parser(char *input, t_env *envi);
void			initialize_sequence(t_token *new, t_env *envi, int index);

#endif 
