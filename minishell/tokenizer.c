/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:50:51 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/22 20:17:56 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokenizer(t_token **tok, char *input, int index)
{
	t_token	*new;

	new = malloc(sizeof(t_token));
	if (!new)
		return (-1);
	initok(new, index);
	space_index(new, input);
	while (input[new->i] && input[new->i] != '|')
	{
		//if (is_redi(input[new->i]))
		//	get_redirection(new, input);
		get_cmd(new, input);
		get_arg(new, input);
	}
	add_last(tok, new);
	return (new->i);
}

void	get_cmd(t_token *new, char *input)
{
	int		j;

	j = -1;
	new->cmd = malloc(sizeof(char) * word_len(input, new->i));
	if (!new->cmd)
		perror("Issue malloc get_cmd");
	if (input[new->i] == '\'')
		get_squote_cmd(new, input);
	else if (input[new->i] == '"')
		get_dquote_cmd(new, input);
	else
	{
		while (input[new->i] && !is_aspace(input[new->i]) && input[new->i] != '|')
		{
			new->cmd[++j] = input[new->i];
			new->i++;
		}
		new->cmd[++j] = '\0';
	}
	new->type = COMMAND;
	new->next = NULL;
	space_index(new, input);
}

/* 
adds the fdwrite or fdread depending
on the redirection needed to the token */
/*void	get_redirection(t_token *new, char *input)
{
	if (input[new->i] == '<')
	{
		new->i++;
		if (input[new->i] == '<')
			rr_left(new, input);
		else
			r_left(new, input);
	}
	else if (input[new->i] == '>')
	{
		new->i++;
		if (input[new->i] == '>')
			rr_right(new, input);
		else
			r_right(new, input);
	}
	space_index(new, input);
	new->pos--;
}
*/

/* adds the arg going with the cmd to token */
void	get_arg(t_token *new, char *input)
{
	new->pos = 0;
	new->arg = malloc(sizeof(char) * 100);
	if (!new->arg)
		perror("Issue malloc get_arg");
	while (input[new->i] && input[new->i] != '|')
	{
		space_index(new, input);
		if (input[new->i] == '\'')
			get_squote(new, input);
		else if (input[new->i] == '"')
			get_dquote(new, input);
		//else if (is_redi(input[new->i]))
		//	get_redirection(new, input);
		else
			get_word(new, input);
		new->pos++;
	}
	new->arg[new->pos] = NULL;
}

/* returns the length of the next word to be malloc*/
int	word_len(char *input, int i)
{
	int	len;

	len = 0;
	while (input[i] && !isdeli(input[i], '!'))
	{
		len++;
		i++;
	}
	return (len + 1);
}
