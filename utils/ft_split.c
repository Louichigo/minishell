/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 18:02:50 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/06 15:28:36 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	svp(size_t count, char **str, int i)
{
	str[i] = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (0);
	return (1);
}

static int	nbrmots(char const *str, char c)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (i > 0 && str[i] && str[i - 1] == c)
			count++;
		if (str[i])
			i++;
	}
	if (str[0] != c)
		count++;
	return (count);
}

static char	**mallo(char **str, char const *s, char c)
{
	size_t	count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
			count++;
		else if (j > 0 && s[j - 1] != c)
		{
			svp(count, str, i);
			count = 0;
			i++;
		}
		if (s[j + 1] == '\0' && s[j] != c)
			svp(count, str, i);
		j++;
	}
	return (str);
}

static char	**copy(char **str, char const *s, char c)
{
	int	i;
	int	j;
	int	x;

	i = 0;
	j = 0;
	x = 0;
	while (s[x])
	{
		if (s[x] != c)
			str[i][j++] = s[x];
		else if (x > 0 && s[x - 1] != c)
		{
			if (x != 0)
			{
				str[i][j] = '\0';
				j = 0;
				i++;
			}
		}
		if (s[x + 1] == '\0' && s[x] != c)
			str[i][j] = '\0';
		x++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		nbmots;

	if (!s || !*s)
	{
		str = malloc(sizeof(char *) * 1);
		if (!str)
			return (NULL);
		*str = (void *)0;
		return (str);
	}
	nbmots = nbrmots(s, c);
	str = malloc(sizeof(char *) * (nbmots + 1));
	if (!str)
		return (0);
	if (mallo(str, s, c) != 0)
		copy(str, s, c);
	else
	{
		free(str);
		return (NULL);
	}
	str[nbmots] = (void *)0;
	return (str);
}
