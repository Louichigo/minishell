/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:26:30 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/18 12:21:29 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(t_token *tok, int i)
{
	clear_history();
	free_token(&tok);
	printf("exit\n");
	exit(i);
}

int	ft_exit_parse(t_token *s)
{
	char	*str;
	int		i;

	i = 0;
	if (s->arg[0] == NULL)
	{
		ft_exit(s, 0);
		return (0);
	}
	str = ft_dechar(s->arg);
	i = exit_error(str);
	free(str);
	ft_exit(s, i);
	return (i);
}

int	exit_error(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr_fd("minishell: exit: numeric argument required\n", 2);
			return (1);
		}
		i++;
	}
	return (0);
}
