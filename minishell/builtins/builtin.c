/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:52:09 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/31 12:17:36 by cgross           ###   ########.fr       */
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

int	exec_builtin(t_token *s, t_env *env)
{
	if (ft_strcmp(s->cmd, "exit") == 0)
		globalv = ft_exit(env);
	else if (ft_strcmp(s->cmd, "env") == 0)
		globalv = ft_env(env, s);
	else if (ft_strcmp(s->cmd, "unset") == 0) //premier segfault
		globalv = ft_unset_parse(s, env);
	else if (ft_strcmp(s->cmd, "export") == 0)
		globalv = ft_export_parse(s, env);
	else if (ft_strcmp(s->cmd, "pwd") == 0)
		globalv = ft_pwd();
	else if (ft_strcmp(s->cmd, "cd") == 0)
		globalv = ft_cd_parse(s, env);
	else if (ft_strcmp(s->cmd, "echo") == 0) //!!!!!!!!!!
		globalv = ft_echo_parse(s, env);
	return (globalv);
}

