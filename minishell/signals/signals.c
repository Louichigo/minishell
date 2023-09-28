/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:05:33 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/13 14:29:00 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handler(int num)
{
	if (num == SIGINT && (g_globalv == 42 || g_globalv == 43))
	{
		ft_putstr_fd("^C \n", 2);
		g_globalv = 130;
	}
	else if (num == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_globalv = 1;
	}
	if (num == SIGQUIT && (g_globalv == 42 || g_globalv == 43))
	{
		ft_putstr_fd("^\\Quit: 3\n", 2);
		g_globalv = 131;
	}
	else if (num == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
		g_globalv = 0;
	}
}

void	signalsinit(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}
