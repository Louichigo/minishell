/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:13:59 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/21 15:37:45 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	removefirst(t_env **root)
{
	t_env *temp = *root;
	*root = (*root)->next;
	free(temp->value);
	free(temp->name);
	temp = 0;
	free(temp);
}


void	ft_unset(t_env *env, char *name)
{
	t_env *curr = env;

	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			if (!curr->previous)
			{
				curr->next->previous = NULL;
				removefirst(&curr);
				return;
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
			return;
		}
		if (!curr->next)
			break;
		curr = curr->next;
	}
}