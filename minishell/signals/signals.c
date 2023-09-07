/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:05:33 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/07 15:41:57 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handler(int num)
{
	if (num == SIGINT)
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_globalv = 1;
	}
}

void	signalsinit(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN);
}
