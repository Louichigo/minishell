/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:52:09 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/28 21:50:16 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtin(t_token *s)
{
	int is = 0;

	if (ft_strcmp(s->cmd, "exit") == 0)
		is = 1;
	else if (ft_strcmp(s->cmd, "env") == 0)
		is = 1;
	else if (ft_strcmp(s->cmd, "unset") == 0)
		is = 1;
	else if (ft_strcmp(s->cmd, "export") == 0)
		is = 1;
	else if (ft_strcmp(s->cmd, "pwd") == 0)
		is = 1;
	else if (ft_strcmp(s->cmd, "cd") == 0)
		is = 1;
	else if (ft_strcmp(s->cmd, "echo") == 0)
		is = 1;
	return (is);
}

void	exec_builtin(t_token *s, t_env *env)
{
	if (ft_strcmp(s->cmd, "exit") == 0)
		ft_exit(env);
	else if (ft_strcmp(s->cmd, "env") == 0)
		ft_env(env, s);
	else if (ft_strcmp(s->cmd, "unset") == 0) //premier segfault
		ft_unset_parse(s, env);
	else if (ft_strcmp(s->cmd, "export") == 0)
		ft_export_parse(s, env);
	else if (ft_strcmp(s->cmd, "pwd") == 0)
		ft_pwd();
	else if (ft_strcmp(s->cmd, "cd") == 0)
		ft_cd_parse(s, env);
	else if (ft_strcmp(s->cmd, "echo") == 0) //!!!!!!!!!!
		ft_echo_parse(s, env);
}

