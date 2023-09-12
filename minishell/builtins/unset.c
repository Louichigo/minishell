/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:13:59 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/12 12:07:25 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
/*
	t_env *temp;

	temp = *env;
	if (temp->next == NULL)
	{
		*env = NULL;
		return;
	}
	*env = (*env)->next;
	(*env)->previous = NULL;
	free(temp->name);
	free(temp->value);
	free(temp);
}
*/
void	ft_unset(t_env **env, char *name)
{
	t_env	*curr;

	curr = *env;
	if (curr == NULL)
		return ;
	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			if (!curr->previous)
			{
				*env = curr->next;
				if (env != NULL)
					(*env)->previous = NULL;
				else
				{
					curr->previous->next = curr->next;
					if (curr->next != NULL)
						curr->next->previous = curr->previous;
				}
				free(curr->name);
				free(curr->value);
				free(curr);
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
	if (ft_strchr(str, '='))
	{
		ft_putstr_fd("minishell: unset: ", 2);
		ft_putstr_fd("'", 2);
		ft_putstr_fd(str, 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		free(str);
		return (1);
	}
	ft_unset(&env, str);
	free(str);
	return (0);
}
