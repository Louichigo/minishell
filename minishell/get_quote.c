/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:02:23 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/25 14:06:34 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_squote_cmd(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
	while (input[new->i] && input[new->i] != '\'')
	{
		new->cmd[++j] = input[new->i];
		new->i++;
	}
	new->cmd[++j] = '\0';
	new->i++;
}

void	get_dquote_cmd(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
	while (input[new->i] && input[new->i] != '"')
	{
			new->cmd[++j] = input[new->i];
			new->i++;
	}
	new->cmd[++j] = '\0';
	new->i++;
}
