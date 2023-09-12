/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:48:58 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/11 17:37:43 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	fullspace(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (input[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_arglen(t_token *s)
{
	int	i;

	i = 0;
	while (s->arg[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[len]);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
