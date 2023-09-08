/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:48:58 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/08 14:39:03 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_putdollar(t_token *s, t_env *env, char *str, int len)
{
	char	*newstr;
	char	*dstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dstr = NULL;
	newstr = malloc(sizeof(char) * len + 1);
	while (str[i])
	{
		if (str[i] == 36)
		{
			i++;
			while (str[i] != '\0' && str[i] != 32)
			{
				newstr[j++] = str[i++];
			}
			newstr[j] = '\0';
			break ;
		}
		i++;
	}
	dstr = if_dollar(s, env, newstr);
	return (dstr);
}

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
