/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_quote.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:02:23 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/22 20:09:02 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* adds what is between the single quotes to the arg at pos */
void	get_squote_cmd(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
	while (input[new->i] && input[new->i] != '\'')
	{
		new->cmd[++j] = input[new->i];
		new->i++;
	}
	new->cmd[++j] = '\0';
	new->i++;
}

/* adds what is between double quotes to arg and if $env
	adds it to pos + 1 and adds rest of string to pos + 2 */
void	get_dquote_cmd(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
	while (input[new->i] && input[new->i] != '"')
	{
			new->cmd[++j] = input[new->i];
			new->i++;
	}
	new->cmd[++j] = '\0';
	new->i++;
}

/* adds what is between the single quotes to the arg at pos */
void	get_squote(t_token *new, char *input)
{
	int	j;

	j = -1;
	new->i++;
//	add_tab(new, new->pos);
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

/* adds what is between double quotes to arg and if $env
	adds it to pos + 1 and adds rest of string to pos + 2 */
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
		if (is_aspace(new->arg[new->pos][j]))
			new->arg[new->pos][j] = '\0';
		else
			new->arg[new->pos][++j] = '\0';
	}
	if (new->flag == 3)
		new->pos++;
	new->arg[new->pos] = malloc(sizeof(char) \
	* mystrcspn(input, " \t", new->i) + 1);
	j = -1;
	while (input[new->i] && !is_aspace(input[new->i]) && input[new->i] != '"')
	{
		new->arg[new->pos][++j] = input[new->i];
		new->i++;
	}
	new->arg[new->pos][++j] = '\0';
	new->arg[++new->pos] = malloc(sizeof(char) \
	* mystrcspn(input, "\"", new->i) + 1);
	if (is_aspace(input[new->i]) && input[new->i + 1] != '$')
		new->i++;
	j = -1;
	return (j);
}