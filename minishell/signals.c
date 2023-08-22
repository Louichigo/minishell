/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:05:33 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/22 19:11:47 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handler(int num)
{
	if (num == SIGQUIT)  //sigquit = ctrl+\ ne rien faire 
	{
		rl_on_new_line();
		rl_redisplay();
	}
	if (num == SIGINT)
		printf("\n");    //sigint = ctrl+c
}

void	signalsinit(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}