/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:31:28 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/11 19:07:24 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lexer(t_data *s, t_env *env)
{
	s->lexer = ft_split(s->line, ' ');
	if (ft_strcmp(s->line, "env") == 0)
		ft_env(env);
	if (ft_strcmp(s->line, "pwd") == 0)
		ft_pwd();
	if (ft_strcmp(s->line, "exit") == 0)
		ft_exit();
	if (strcmp(s->line, "\\") == 0)
		ft_echo(s);
	free(s->line);
	
}

