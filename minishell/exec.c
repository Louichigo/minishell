/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:17:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/30 15:20:33 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(t_token *s, t_env *env)
{
	if (is_builtin(s) == 1)
		exec_builtin(s, env);
	//else if (//dollar)
	else
	{
		parse_exec(s);
		exec_cmd(s->arg_all, NULL);
		ft_freeall(s->arg_all);
	}
}

void	ft_freeall(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
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