/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:22:08 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/11 15:24:05 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char *str, int echon)
{
	write(1, str, ft_strlen(str));
	if (echon == 0)
		write(1, "\n", 1);
}

int	ft_echo_parse(t_token *s, t_env *env)
{
	char	*str;
	char	*dollar;
	char	*finalstr;
	int		i;

	i = 0;
	dollar = NULL;
	if (s->arg[0] == NULL)
	{
		printf("\n");
		return (0);
	}
	if (ft_strcmp(s->arg[0], "-n") == 0)
		i = 1;
	str = ft_echon(s->arg, i);
	if (s->issquote != 1)
		dollar = ft_finddollar(s, env, str);
	if (dollar == NULL || s->dollartemp == 0 || s->issquote == 1)
	{
		ft_echo(str, i);
		free(str);
		return (0);
	}
	finalstr = ft_jenpeuxplus(s, str, dollar);
	ft_echo(finalstr, i);
	free(finalstr);
	free(str);
	free(dollar);
	return (0);
}

char	*ft_jenpeuxplus(t_token *s, char *str, char *dollar)
{
	char	*newstr;
	int		len;
	int		i;
	int		j;

	i = 0;
	j = 0;
	len = ft_strlen(str) - (s->count + 1) + ft_strlen(dollar);
	newstr = malloc(sizeof(char) * len + 1);
	len = 0;
	while (str[len] != 36)
		newstr[i++] = str[len++];
	while (str[len] != '\0' && str[len] != 32)
		len++;
	while (dollar[j])
	{
		newstr[i++] = dollar[j++];
	}
	while (str[len] != '\0')
		newstr[i++] = str[len++];
	newstr[i++] = '\0';
	return (newstr);
}

char	*ft_finddollar(t_token *s, t_env *env, char *str)
{
	int		i;
	int		start;
	char	*newstr;

	i = 0;
	newstr = NULL;
	s->count = 0;
	start = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 36)
		{
			i++;
			start = i;
			while (str[i] != '\0' && str[i] != 32)
				i++;
			s->count = i - start;
			newstr = ft_putdollar(s, env, str, s->count);
			return (newstr);
		}
		i++;
	}
	return (newstr);
}

char	*ft_echon(char **str, int i)
{
	char	*newstr;
	int		len;
	int		k;
	int		j;

	k = 0;
	len = ft_fulllen(str, i);
	newstr = malloc(sizeof(char) * len);
	if (!newstr)
		return (NULL);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
			newstr[k++] = str[i][j++];
		i++;
		if (i < len - 1)
			newstr[k++] = 32;
	}
	newstr[k] = '\0';
	return (newstr);
}
