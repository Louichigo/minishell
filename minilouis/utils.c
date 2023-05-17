/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 13:43:58 by lobertho          #+#    #+#             */
/*   Updated: 2023/05/17 16:22:50 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_command_to_history(t_data *s)
{
	int	i;

	i = 1;
	s->ith = s->history_count;
	if (s->history_count < HISTSIZE)
	{
		s->history[s->history_count++] = ft_strdup(s->line);
	}
	else
	{
		free(s->history[0]);
		while (i < HISTSIZE)
		{
			s->history[i - 1] = s->history[i];
			i++;
		}
		s->history[HISTSIZE -1] = ft_strdup(s->line);
	}
}

int	ft_len(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(sizeof(char) * ft_len(s1) + 1);
	if (!dest)
		return (0);
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
	free (dest);
}
