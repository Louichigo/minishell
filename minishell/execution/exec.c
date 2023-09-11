/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:17:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/11 13:32:01 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execution(t_token *s, t_env *env)
{
	if (!s->next)
	{
		exec_cmd(s, env, NULL);
		if (is_builtin(s) != 1)
			ft_free(s->arg_all);
	}
	else
		exec_cmds(s, env);
}

void	exec_cmd(t_token *s, t_env *env, char **envp)
{
	if (is_builtin(s) == 1)
	{
		exec_builtin(s, env);
		return ;
	}
	s->exit_status = 0;
	s->pid = 0;
	g_globalv = 42;
	s->pid = fork();
	if (s->pid == -1)
		perror("minishell: fork error");
	parse_exec(s);
	if (s->pid == 0)
	{
		if (execve(get_right_path(env, *s->arg_all), s->arg_all, envp) == -1)
			ft_error(s, *s->arg_all);
		exit(g_globalv);
	}
	else
	{
		wait(&s->exit_status);
		if (WIFEXITED(s->exit_status))
			g_globalv = WEXITSTATUS(s->exit_status);
	}
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
