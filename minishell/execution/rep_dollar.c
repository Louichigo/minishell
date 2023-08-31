/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rep_dollar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:11:26 by cgross            #+#    #+#             */
/*   Updated: 2023/08/31 13:00:57 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	replace_dollar(t_token *tok)
{
	int	i;

	i = 0;
	while (tok->arg[i])
	{
		if (tok->arg[i][0] == '$')
		{
			if (tok->arg[i][1] == '?')
			{
				free(tok->arg[i]);
				tok->arg[i] = ft_itoa(globalv);
			}
		}
		i++;
	}
}
