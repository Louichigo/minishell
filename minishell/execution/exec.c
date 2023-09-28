/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:17:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/15 11:33:23 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execution(t_token *s, t_env *env, char **envp)
{
	if (!s->next)
	{
		exec_cmd(s, env, envp);
		if (is_builtin(s) != 1)
			ft_free(s->arg_all);
	}
	else
		exec_cmds(s, env, envp);
}

void	exec_cmd(t_token *s, t_env *env, char **envp)
{
	int	init_stdin;
	int	init_stdout;

	init_stdin = dup(STDIN_FILENO);
	init_stdout = dup(STDOUT_FILENO);
	s->exit_status = 0;
	if (s->fdread >= 3)
		dup2(s->fdread, STDIN_FILENO);
	if (s->fdwrite >= 3)
		dup2(s->fdwrite, STDOUT_FILENO);
	if (is_builtin(s) == 1)
		exec_builtin(s, env);
	else
		exec_external(s, env, envp);
	if (s->fdread >= 3)
		close(s->fdread);
	if (s->fdwrite >= 3)
		close(s->fdwrite);
	dup2(init_stdin, STDIN_FILENO);
	dup2(init_stdout, STDOUT_FILENO);
	close(init_stdin);
	close(init_stdout);
}

void	parse_exec(t_token *s)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	j = 0;
	s->sizearg = ft_arglen(s);
	s->arg_all = malloc(sizeof(char *) * (2 + s->sizearg));
	s->arg_all[0] = ft_strdup(s->cmd);
	while (s->arg[j])
	{
		k = 0;
		s->arg_all[i] = malloc(sizeof(char) * (ft_strlen(s->arg[j]) + 1));
		while (s->arg[j][k])
		{
			s->arg_all[i][k] = s->arg[j][k];
			k++;
		}
		s->arg_all[i][k] = '\0';
		i++;
		j++;
	}
	s->arg_all[i] = NULL;
}

void	exec_external(t_token *s, t_env *env, char **envp)
{
	pid_t	pid;
	int		exit_status;

	parse_exec(s);
	if (g_globalv == 1)
		g_globalv = 42;
	else if (g_globalv != 0)
		g_globalv = 43;
	pid = fork();
	if (pid == -1)
		perror("minishell: fork error");
	if (pid == 0)
	{
		if (execve(get_right_path(env, *s->arg_all), s->arg_all, envp) == -1)
			ft_error(s, *s->arg_all);
		exit(g_globalv);
	}
	else
	{
		waitpid(pid, &exit_status, 0);
		if (WIFEXITED(exit_status))
			g_globalv = WEXITSTATUS(exit_status);
	}
}
