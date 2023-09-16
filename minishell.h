/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:19 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/16 11:02:19 by cgross           ###   ########.fr       */
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
# include <termios.h>
# include <errno.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

extern int	g_globalv;

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
	struct s_env	*previous;
}	t_env;

typedef struct s_token
{
	int					exit;
	int					exit_status;
	int					isbquote;
	int					issquote;
	int					type;
	int					sizearg;
	int					dollartemp;
	int					c;
	int					flag;
	int					g_flag;
	int					error;
	int					flag_env[100];
	int					syntax;
	int					i;
	int					len;
	int					dj;
	int					di;
	int					nbc;
	int					pos;
	int					temp;
	int					env_len;
	int					file_type;
	int					fdwrite;
	int					fdread;
	char				*newstr;
	char				*itoa;
	char				*exportname;
	char				*exportvalue;
	char				*end_of_file;
	char				*cmd;
	char				**arg;
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

void	ft_echo(int arg, char *str, t_token *s, t_env *env);
void	ft_exit(t_token *tok, int i);
void	exec_cmd(t_token *s, t_env *env, char **envp);
void	exec_external(t_token *token, t_env *env, char **envp);
void	ft_free(char **str);
void	free_token(t_token **token);
void	free_double(t_token *token);
void	ft_export(t_env *env, char *name, char *value);
void	ft_unset(t_env *env, char *name);
void	signalsinit(void);
void	ft_putstr_fd(char *s, int fd);
void	add_tab(t_token *token, int new);
void	execution(t_token *s, t_env *env, char **envp);
void	parse_exec(t_token *s);
void	ft_error(t_token *s, char *cmd);
void	init_termios(void);
void	get_cmd(t_token *new, char *input);
void	get_redirection(t_token *new, char *input);
void	get_arg(t_token *new, char *input);
void	space_index(t_token *new, char *input);
void	add_last(t_token **head, t_token *new);
void	print_list(t_token *head);
void	get_word(t_token *new, char *input);
void	get_squote(t_token *new, char *input);
void	get_dquote(t_token *new, char *input);
void	get_squote_cmd(t_token *new, char *input);
void	get_dquote_cmd(t_token *new, char *input);
void	heredoc(t_token *new, char *input);
void	r_left(t_token *new, char *input);
void	rr_left(t_token *new, char *input);
void	r_right(t_token *new, char *input);
void	rr_right(t_token *new, char *input);
void	parser(char	*input, t_env *envi, char **envp);
void	initialize_sequence(t_token *new, t_env *envi, int index);
void	error(char *str);
void	exec_cmds(t_token *token, t_env *env, char **envp);
void	prep_fd(t_token *token, int *fd_pipe_tmp, int *fd_pipe);
void	close_fd(t_token *token, int *fd_pipe_tmp, int *fd_pipe);
void	analyse_arg(char *str, t_token *s, t_env *env);
void	check_dollar(t_token *s, int len, char *str, t_env *env);
void	ft_itog(void);
void	print_error(t_token *s);

int		ft_pwd(void);
int		ft_env(t_env **env, t_token *s);
int		ft_exit_parse(t_token *s);
int		ft_cd(t_env *env, char *str);
int		cd_cond(t_env *env, char *str);
int		exec_builtin(t_token *s, t_env *env);
int		ft_export_parse(t_token *s, t_env *env);
int		ft_unset_parse(t_token *s, t_env *env);
int		ft_cd_parse(t_token *s, t_env *env);
int		ft_echo_parse(t_token *s, t_env *env);
int		fullspace(char *input);
int		is_builtin(t_token *s);
int		ft_fulllen(char **str, int i);
int		ft_strcmp(char *s1, char *s2);
int		ft_arglen(t_token *s);
int		sequencer(t_token **head, char *input, t_env *envi, int index);
int		word_len(char *input, int i);
int		isredi(char c);
int		isdeli(char c, char flag);
int		ft_isaspace(char c);
int		mystrcspn(char *s, char *reject, int i);
int		iscontained(char *here, char *eof);
int		isword(char *here, char *eof, int index);
int		exit_error(char *str);
int		mute_stuff(t_token *tok);
int		mr_bricolage(t_token *s);

t_env	*init_env(char **envp);

t_token	*get_last(t_token *head);

size_t	ft_strlen(const char *s);

bool	check_quotes(char *input);

char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_right_path(t_env *env, char *cmd);
char	*ft_strdup(const char *s1);
char	*ft_splitname(char *str);
char	*ft_splitvalue(char *str);
char	*ft_dechar(char **str);
char	*find_var(t_env *env, char *name);
char	*ft_itoa(int n);
char	*get_filename(t_token *new, char *input);

char	**get_all_path(t_env *env);
char	**ft_split(char const *s, char c);

#endif 
