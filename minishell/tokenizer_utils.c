/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:54:25 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/22 19:54:37 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_redi(char c)
{
	if (c == '<' || c == '>')
		return (true);
	return (false);
}

bool	is_aspace(char c)
{
	if (c == ' ' || c == '\t')
		return (true);
	return (false);
}

/* returns true if char is a delimiter
	if flag == s takes into account the spaces */
bool	isdeli(char c, char flag)
{
	if (c == '|' || c == '<' || c == '>')
		return (true);
	if (flag == 's' && is_aspace(c))
		return (true);
	return (false);
}

//iterates the index after removing the spaces
void	space_index(t_token *new, char *input)
{
	while (input[new->i] && is_aspace(input[new->i] == true))
		new->i++;
}