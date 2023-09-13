/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:12:13 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/13 14:32:54 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error(t_token *s, char *cmd)
{
	s->itoa = NULL;
	if (ft_strchr(cmd, '/') != NULL)
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(s->cmd, 2);
		ft_putstr_fd(": No such file or directory\n", 2);
		g_globalv = 1;
	}
	else
	{
		if (g_globalv == 42)
			g_globalv = 1;
		else
			g_globalv = 127;
		s->itoa = ft_itoa(g_globalv);
		ft_putstr_fd("minishell: ", 2);
		if (ft_strcmp(cmd, "$?") == 0)
			ft_putstr_fd(s->itoa, 2);
		else
			ft_putstr_fd(s->cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		free(s->itoa);
		g_globalv = 127;
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
