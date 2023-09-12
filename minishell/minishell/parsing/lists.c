/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:11:01 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/31 13:01:20 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_last(t_token **head, t_token *new)
{
	t_token		*tmp;

	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	tmp = get_last(*head);
	tmp->next = new;
}

t_token	*get_last(t_token *head)
{
	t_token	*tmp;

	if (!head)
		return (NULL);
	tmp = head;
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	print_list(t_token *head)
{
	t_token	*tmp;
	int		j;

	tmp = head;
	while (tmp)
	{
		j = -1;
		printf("cmd: %s ", tmp->cmd);
		while (tmp->arg[++j])
		{
			printf("arg: %s", tmp->arg[j]);
		}
		printf("\n");
		tmp = tmp->next;
	}
}
