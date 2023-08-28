/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:38:44 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/28 18:40:22 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_env *env, char *name, char *value)
{
	t_env *curr = env;

	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			free(curr->value);
			curr->value = ft_strdup(value);
			return ;
		}
		if (!curr->next) 
			break;
		curr = curr->next;
	}
	t_env *new_var = malloc(sizeof(t_env));
	new_var->name = ft_strdup(name);
	new_var->value = ft_strdup(value);
	new_var->next = NULL;
	curr->next = new_var;
	curr->next->previous = curr;
}

void	ft_export_parse(t_token *s, t_env *env)
{
	char *str;

	str = ft_dechar(s->arg);
	s->exportname = ft_splitname(str);
	s->exportvalue = ft_splitvalue(str);
	free(str);
	ft_export(env, s->exportname, s->exportvalue);
	free(s->exportname);
	free(s->exportvalue);
}