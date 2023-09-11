/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:52:09 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/08 14:28:08 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	is_builtin(t_token *s)
{
	int	is;

	is = 0;
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
		g_globalv = ft_exit_parse(s, env);
	else if (ft_strcmp(s->cmd, "env") == 0)
		g_globalv = ft_env(&env, s);
	else if (ft_strcmp(s->cmd, "unset") == 0)
		g_globalv = ft_unset_parse(s, env);
	else if (ft_strcmp(s->cmd, "export") == 0)
		g_globalv = ft_export_parse(s, env);
	else if (ft_strcmp(s->cmd, "pwd") == 0)
		g_globalv = ft_pwd();
	else if (ft_strcmp(s->cmd, "cd") == 0)
		g_globalv = ft_cd_parse(s, env);
	else if (ft_strcmp(s->cmd, "echo") == 0)
		g_globalv = ft_echo_parse(s, env);
	return (g_globalv);
}
