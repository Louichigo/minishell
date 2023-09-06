/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:54:25 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/31 13:01:35 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	isredi(char c)
{
	if (c == '<' || c == '>')
		return (1);
	return (0);
}

int	isdeli(char c, char flag)
{
	if (c == '|' || c == '<' || c == '>')
		return (1);
	if (flag == 's' && ft_isaspace(c))
		return (1);
	return (0);
}

int	ft_isaspace(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

void	space_index(t_token *new, char *input)
{
	while (input[new->i] && ft_isaspace(input[new->i]))
		new->i++;
}
