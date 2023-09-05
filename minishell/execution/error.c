/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:12:13 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/05 18:21:50 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error(t_token *s, char *cmd)
{
	if (ft_strchr(cmd, '/') != NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(s->cmd, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		globalv = 1;
	}
	else
	{
		globalv = 127;
		ft_putstr_fd("minishell: ", 2);
		if (ft_strcmp(cmd, "$?") == 0)
			ft_putstr_fd(ft_itoa(globalv), 2);
		else
			ft_putstr_fd(s->cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}