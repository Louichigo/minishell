/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:54:24 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/22 19:13:39 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_freeenv(t_env *env)
{
	t_env *curr = env;
	while (curr)
	{
		free(curr->name);
		free(curr->value);
		curr = curr->next;
	}
	free(curr);
	free(env);	
}