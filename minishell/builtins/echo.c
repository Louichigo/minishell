/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:22:08 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/12 12:52:38 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"


//prendre apres le dollar jusqua la fin de l'arg
//chercher si env ou $? puis imprimer puis fin arg 
//quand fin argument imprimer espace sauf si dernier argument

void	ft_echo(int	arg, char *str, t_token *s, t_env *env)
{
	int	i;

	i = 0;
	(void)env;
	while (str[i])
	{
		if (str[i] == '$' && s->issquote != 1)
		{
			//analyse_arg(&str[i], s, env);
			break ;
		}
		else
			write(1, &str[i], 1);
		i++;
	}
	if (arg == 0)
		write(1, " ", 1);
}

int	ft_echo_parse(t_token *s, t_env *env)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	if (s->arg[0] == NULL)
	{
		printf("\n");
		return (0);
	}
	if (ft_strcmp(s->arg[0], "-n") == 0)
		i = 1;
	j = i;
	len = ft_arglen(s);
	while (s->arg[j])
	{
		if (j == (len - 1) || s->issquote == 1 || s->isbquote == 1)
			ft_echo(len, s->arg[j++], s, env);
		else
			ft_echo(0, s->arg[j++], s, env);
	}
	if (i == 0)
		write(1, "\n", 1);
	return (0);
}

//avancer jusqua dollar et apres si ? on print la gglobal et la suite de l arg
//sinon on fait une string avec tt le reste de l'arg et on fait if_dollar
//pour print la variable si c bon

/*void	analyse_arg(char *str, t_token *s, t_env *env)
{
	s->di = 0;
	s->newstr = NULL;
	while (str[s->di] != '$')
			s->di++;
	while (str[s->di] != '\0')
	{
		s->dj = 0;
		while (str[s->di] != '$')
			write(1, &str[s->di], 1);
		s->di++;
		if (str[s->di] == '?')
			write(1, &g_globalv, 1);
		else
		{
			s->count = s->di;
			while (str[s->di] != '\0' && str[s->di] != '$')
				s->di++;
			s->di = (s->di - s->count + 1);
			newstr = malloc(sizeof(char) * s->di);
			while (str[s->count] != '\0' && str[s->count] != '$')
				s->newstr[s->dj++] = str[s->count++];
			s->newstr[s->dj] = '\0';
			//check_dollar();
			free(s->newstr);
		}
		s->di++;
	}
}*/