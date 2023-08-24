/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 13:02:24 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/23 16:26:05 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_splitname(char *str)
{
	int		i;
	char	*name;

	i = 0;
	while (str[i] != '=')
		i++;
	name = malloc(sizeof(char) * i + 1);
	i = 0;
	while(str[i] != '=')
	{
		name[i] = str[i];
		i++;
	}
	name[i] = '\0';
	return (name);
}

char *ft_splitvalue(char *str)
{
	int		i;
	int		j;
	char	*value;

	i = 0;
	j = 0;
	while (str[i] != '=')
		i++;
	i++;
	j = i;
	while (str[i])
		i++;
	i = i - j;
	value = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[j] != '\0')
		value[i++] = str[j++];
	value[i] = '\0';
	return (value);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write (fd, &s[i++], 1);
}

int	mystrcspn(char *s, char *reject, int i)
{
	int	j;
	int	len;

	len = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (reject[j] != '\0')
		{
			if (s[i] == reject[j])
				return (len);
			j++;
		}
		len++;
		i++;
	}
	return (len + 1);
}

/* adds the characters until space or delimiters
and adds it in the token->arg at arg[pos], with a malloc */
void	get_word(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->arg[new->pos] = malloc(sizeof(char) * word_len(input, new->i));
	if (!new->arg[new->pos])
		perror("Issue malloc get_word");
	while (input[new->i] && !isdeli(input[new->i], 's'))
	{
		new->arg[new->pos][++j] = input[new->i];
		new->i++;
	}
	new->arg[new->pos][++j] = '\0';
	space_index(new, input);
}