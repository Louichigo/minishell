/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:12:13 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/04 15:12:26 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_error(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '/')
		{
			ft_putstr_fd("error: No such file or directory\n", 2);
			return (1);
		}
		i++;
	}
	if (cmd)
		ft_putstr_fd("error: command not found\n", 2);
	else
		return (127);
	return (1);
}
