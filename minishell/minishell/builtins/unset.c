/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:13:59 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/06 15:43:10 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*t_env *temp = *env;
	if (temp->next == NULL)
	{
		*env = NULL;
		return;
	}
	*env = (*env)->next;
	(*env)->previous = NULL;
	free(temp->name);
	free(temp->value);
	free(temp);*/

void	ft_unset(t_env **env, char *name)
{
	t_env	*curr;
	t_env	*temp;

	curr = *env;
	temp = *env;
	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			if (!curr->previous)
			{
				if (temp->next == NULL)
				{
					*env = NULL;
					return ;
				}
				(*env) = (*env)->next;
				(*env)->previous = NULL;
				free(temp->name);
				free(temp->value);
				free(temp);
				return ;
			}
			else if (!curr->next)
				curr->previous->next = NULL;
			else
			{
				curr->previous->next = curr->next;
				curr->next->previous = curr->previous;
			}
			free(curr->value);
			free(curr->name);
			curr = NULL;
			free(curr);
			free(temp);
			return ;
		}
		if (!curr->next)
			break ;
		curr = curr->next;
	}
}

int	ft_unset_parse(t_token *s, t_env *env)
{
	char	*str;

	str = ft_dechar(s->arg);
	ft_unset(&env, str);
	free(str);
	return (0);
}
