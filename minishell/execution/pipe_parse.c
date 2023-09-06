/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:34:35 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/06 15:09:37 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_nbrdecommandes(t_token *s)
{

	s->nbc = 0;
	while (s)
	{
		s->nbc++;
		if (!s->next)
			break;
		s = s->next;
	}
	return (s->nbc);
}

void	pipe_parse(t_token *s, t_env *env)
{
	int		i;
	char	**pipecmd;

	i = 0;
	(void)env;
	pipecmd = malloc(sizeof(char *) * ft_nbrdecommandes(s) + 1);
	while (s)
	{
		parse_exec(s);
		pipecmd[i] = ft_clabonne(s->arg_all);
		ft_free(s->arg_all);
		i++;
		if (!s->next)
			break;
		s = s->next;
	}
	pipecmd[i] = NULL;
	globalv = pipex(s, env, pipecmd[0], pipecmd[1]);
	ft_free(pipecmd);
}