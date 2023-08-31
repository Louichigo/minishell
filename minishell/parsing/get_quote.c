/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:02:23 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/31 13:01:07 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

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
