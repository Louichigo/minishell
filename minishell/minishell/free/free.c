/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/17 12:54:24 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/07 14:58:43 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_token(t_token **head)
{
	t_token	*tmp;
	t_token	*stock;

	stock = *head;
	while (stock)
	{
		tmp = stock;
		stock = stock->next;
		free_double(tmp);
		free(tmp->cmd);
		if (tmp->end_of_file)
			free(tmp->end_of_file);
		free(tmp);
	}
	*head = NULL;
}

void	free_double(t_token *token)
{
	int	i;

	i = -1;
	if (token->arg)
	{
		while (token->arg[++i])
			free(token->arg[i]);
		free(token->arg);
	}
}

void	ft_freeenv(t_env *env)
{
	t_env	*curr;

	curr = env;
	while (curr)
	{
		free(curr->name);
		free(curr->value);
		curr = curr->next;
	}
	free(curr);
	free(env);
}
