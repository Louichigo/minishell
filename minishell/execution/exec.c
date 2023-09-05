/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:17:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/05 11:29:42 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	execution(t_token *s, t_env *env)
{
	if (!s->next)
	{
		if (is_builtin(s) == 1)
			exec_builtin(s, env);
		else
		{
			parse_exec(s);
			exec_cmd(env, s->arg_all, NULL);
			ft_freeall(s->arg_all);
		}
	}
	else if (s->next)
	{
		//pipe
	}
	else
		printf("POURQUOI\n");
}

void	exec_cmd(t_env *env, char **cmd, char **envp)
{
	int	pid = 0;
	int status = 0;

	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		if (execve(get_right_path(env, *cmd), cmd, envp) == -1)
			globalv = ft_error(*cmd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
			globalv = WEXITSTATUS(status);
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

int	ft_arglen(t_token *s)
{
	int i;

	i = 0;
	while (s->arg[i])
		i++;
	return (i);
}