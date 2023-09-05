/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:05:33 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/05 12:17:24 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handler(int num)
{
	if (num == SIGINT)  //sigint = ctrl+c nouveau prompt
	{
		write(1, "\n", 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		globalv = 1;
	}
}

void	signalsinit(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, SIG_IGN); //sigquit = ne rien faire / sig ign dit ignorer le signal
}
