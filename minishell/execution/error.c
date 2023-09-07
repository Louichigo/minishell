/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:12:13 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/07 15:25:50 by cgross           ###   ########.fr       */
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
		g_globalv = 1;
	}
	else
	{
		g_globalv = 127;
		ft_putstr_fd("minishell: ", 2);
		if (ft_strcmp(cmd, "$?") == 0)
			ft_putstr_fd(ft_itoa(g_globalv), 2);
		else
			ft_putstr_fd(s->cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
	}
}

void	error(char *str)
{
	ft_putstr_fd("error: ", 2);
	if (errno)
		perror(str);
	else
		ft_putstr_fd(str, 2);
	exit(EXIT_FAILURE);
}
