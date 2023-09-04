/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:26:30 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/04 14:07:01 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_exit(t_env *env, int i)
{
		clear_history();
		ft_freeenv(env);
		printf("exit\n");
		exit(i);
}

int	ft_exit_parse(t_token *s, t_env *env)
{
	char	*str;
	int		i;

	i = 0;
	if (s->arg == NULL)
	{
		ft_exit(env, 0);
		return (0);
	}
	str = ft_dechar(s->arg);
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			ft_putstr_fd("exit : numeric argument required\n", 2);
			break;
		}
		i++;
	}
	if (str == 0)
		i = 0;
	else
		i = 1;
	free(str);
	ft_exit(env, i);
	return (i);
}

