/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:31:28 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/22 20:18:42 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	closed_quotes(char *input)
{
	bool	closed;
	int		scount;
	int		dcount;
	int		i;

	closed = false;
	i = 0;
	scount = 0;
	dcount = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			scount++;
		if (input[i] == '\"')
			dcount++;
		i++;
	}
	if (scount % 2 == 0 && dcount % 2 == 0)
		closed = true;
	return (closed);
}

void	parser(char *input, t_env *env)
{
	t_token	*tok;
	int		i;

	(void)env;
	tok = NULL;
	i = 0;
	if (closed_quotes(input) == false)
		return (perror("Error with unclosed quotes"));
	while (input[i])
	{
		i = tokenizer(&tok, input,  i);
		if (input[i] == '|')
			i++;
	}
	if (!tok->error)
	{
		//replace usd in input;
		//execute here;
		print_list(tok);
	}
	//free(&tok); need check double free somewhere
}

/* initializes all the element of the linked list */
void	initok(t_token *new, int index)
{
	new->cmd = NULL;
	new->arg = NULL;
	new->next = NULL;
	new->error = 0;
	new->flag = 1;
	new->fdread = 1;
	new->fdwrite = 1;
	new->i = index;
	new->arg_all = NULL;
	new->end_of_file = NULL;
	new->g_env = NULL;
}