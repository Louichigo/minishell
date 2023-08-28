/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:13:59 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/28 20:36:01 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_env **env, char *name)
{
	t_env *curr = *env;

	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			if (!curr->previous)
			{
				t_env	*tempnode = *env;
				if (*env == NULL)
					return ;
				if (tempnode->next == NULL)
				{
					*env = NULL;
					return;
				}
				*env = (*env)->next;
				(*env)->previous = NULL;
				free(tempnode->name);
				free(tempnode->value);
				free(tempnode);
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

void	ft_unset_parse(t_token *s, t_env *env)
{
	char *str;

	(void)env;
	str = ft_dechar(s->arg);
	printf("%s\n", str);
	ft_unset(&env, str);
	free(str);	
}