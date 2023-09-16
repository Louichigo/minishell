/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 15:12:13 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/16 11:04:04 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_error(t_token *s, char *cmd)
{
	if (mute_stuff(s))
		return ;
	s->itoa = NULL;
	if (ft_strchr(cmd, '/') != NULL)
		print_error(s);
	else
	{
		if (g_globalv == 42)
			g_globalv = 1;
		else if (g_globalv == 43)
			g_globalv = 127;
		else
			g_globalv = 0;
		s->itoa = ft_itoa(g_globalv);
		ft_putstr_fd("minishell: ", 2);
		if (ft_strcmp(cmd, "$?") == 0)
			ft_putstr_fd(s->itoa, 2);
		else
			ft_putstr_fd(s->cmd, 2);
		ft_putstr_fd(": command not found\n", 2);
		free(s->itoa);
	}
	g_globalv = mr_bricolage(s);
}

int	mr_bricolage(t_token *s)
{
	if (s->next != NULL)
		return (0);
	return (127);
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

void	print_error(t_token *s)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(s->cmd, 2);
	ft_putstr_fd(": No such file or directory\n", 2);
}

int	mute_stuff(t_token *tok)
{
	if (tok->cmd[0] == '\0')
		return (1);
	else if (tok->cmd[0] == '<' || tok->cmd[0] == '>')
		return (1);
	return (0);
}
