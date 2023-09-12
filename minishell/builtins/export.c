/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:38:44 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/12 12:13:06 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_export(t_env *env, char *name, char *value)
{
	t_env	*curr;
	t_env	*new_var;

	curr = env;
	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			free(curr->value);
			curr->value = ft_strdup(value);
			return ;
		}
		if (!curr->next)
			break ;
		curr = curr->next;
	}
	new_var = malloc(sizeof(t_env));
	new_var->name = ft_strdup(name);
	new_var->value = ft_strdup(value);
	new_var->next = NULL;
	curr->next = new_var;
	curr->next->previous = curr;
}

int	ft_export_parse(t_token *s, t_env *env)
{
	char	*str;

	str = ft_dechar(s->arg);
	if (ft_strchr(str, '='))
		return (0);
	s->exportname = ft_splitname(str);
	s->exportvalue = ft_splitvalue(str);
	if (s->exportname == NULL || s->exportvalue == NULL)
	{
		free(str);
		return (1);
	}
	free(str);
	ft_export(env, s->exportname, s->exportvalue);
	free(s->exportname);
	free(s->exportvalue);
	return (0);
}
