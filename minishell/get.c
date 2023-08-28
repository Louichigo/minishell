/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:02:23 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/25 14:05:36 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	get_squote(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
	add_tab(new, new->pos);
	new->arg[new->pos] = malloc(sizeof(char) \
	* (mystrcspn(input, "\'", new->i) + 2));
	if (!new->arg[new->pos])
	{
		perror("Issue malloc get_squote");
		return ;
	}
	while (input[new->i] && input[new->i] != '\'')
	{
		new->arg[new->pos][++j] = input[new->i];
		new->i++;
	}
	new->arg[new->pos][++j] = '\0';
	new->i++;
}

void	get_dquote(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
	new->arg[new->pos] = malloc(sizeof(char) \
	* (mystrcspn(input, "\"", new->i) + 2));
	if (!new->arg[new->pos])
		perror("Issue malloc get_dquote");
	while (input[new->i] && input[new->i] != '"')
	{
		if (input[new->i] == '$')
			j = env_handler(new, input, j);
		else
		{
			new->flag = 3;
			new->arg[new->pos][++j] = input[new->i];
			new->i++;
		}
	}
	new->arg[new->pos][++j] = '\0';
	new->i++;
}

int	env_handler(t_token *new, char *input, int j)
{
	if (input[new->i - 1] != '"')
	{
		if (ft_isaspace(new->arg[new->pos][j]))
			new->arg[new->pos][j] = '\0';
		else
			new->arg[new->pos][++j] = '\0';
	}
	if (new->flag == 3)
		new->pos++;
	new->arg[new->pos] = malloc(sizeof(char) \
	* mystrcspn(input, " \t", new->i) + 1);
	j = -1;
	while (input[new->i] && !ft_isaspace(input[new->i]) && input[new->i] != '"')
	{
		new->arg[new->pos][++j] = input[new->i];
		new->i++;
	}
	new->arg[new->pos][++j] = '\0';
	new->arg[++new->pos] = malloc(sizeof(char) \
	* mystrcspn(input, "\"", new->i) + 1);
	if (ft_isaspace(input[new->i]) && input[new->i + 1] != '$')
		new->i++;
	j = -1;
	return (j);
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
