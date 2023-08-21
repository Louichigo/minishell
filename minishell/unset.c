/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:13:59 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/13 18:08:15 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	suppfirst(t_env **env)
{
	if (*env == NULL)
		return;
	t_env *supp = *env;
	*env = (*env)->next;
	free(supp->value);
	free(supp->name);
	free(supp);
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
				suppfirst(&curr);
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