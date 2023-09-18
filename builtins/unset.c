/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:13:59 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/18 13:27:23 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	remove_node(t_env **env)
{
	t_env	*temp;

	temp = *env;
	if (temp->next == NULL)
	{
		*env = NULL;
		return ;
	}
	*env = (*env)->next;
	(*env)->previous = NULL;
	temp->name = NULL;
	free(temp->name);
	temp->value = NULL;
	free(temp->value);
	temp = NULL;
	free(temp);
}

void	ft_freeb(t_env *curr)
{
	free(curr->value);
	free(curr->name);
	free(curr);
	curr = NULL;
}

void	ft_unset(t_env *env, char *name)
{
	t_env	*curr;

	curr = env;
	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			if (!curr->previous)
			{
				remove_node(&curr);
				return ;
			}
			else if (!curr->next)
				curr->previous->next = NULL;
			else
			{
				curr->previous->next = curr->next;
				curr->next->previous = curr->previous;
			}
			return (ft_freeb(curr));
		}
		if (!curr->next)
			break ;
		curr = curr->next;
	}
}

int	ft_unset_parse(t_token *s, t_env *env)
{
	char	*str;

	if (s->arg[0] == NULL)
		return (0);
	str = ft_dechar(s->arg);
	ft_unset(env, str);
	free(str);
	return (0);
}
