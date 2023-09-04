/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:05:33 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/04 11:30:06 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	handler(int num)
{
	if (num == SIGINT)  //sigint = ctrl+c nouveau prompt
	{
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		globalv = 1;
	}
	else if (num == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signalsinit(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler); //sigquit = ne rien faire / sig ign dit ignorer le signal
}
