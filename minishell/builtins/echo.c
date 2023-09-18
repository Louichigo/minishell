/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:22:08 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/13 14:34:07 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(int arg, char *str, t_token *s, t_env *env)
{
	int	i;

	i = 0;
	(void)env;
	while (str[i])
	{
		if (str[i] == '$' && s->issquote != 1)
		{
			s->di = 0;
			s->newstr = NULL;
			analyse_arg(&str[i], s, env);
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

void	analyse_arg(char *str, t_token *s, t_env *env)
{
	while (str[s->di] != '\0')
	{
		while (str[s->di] != '$' && str[s->di] != '\0')
			write(1, &str[s->di++], 1);
		if (str[s->di] == '\0')
			return ;
		s->di++;
		s->dj = 0;
		if (str[s->di] == '?')
		{
			ft_itog();
			s->di++;
		}
		else
		{
			s->c = s->di;
			while (str[s->di] != '\0' && str[s->di] != '$' && str[s->di] != 32)
				s->di++;
			s->len = (s->di - s->c + 1);
			s->newstr = malloc(sizeof(char) * s->len);
			while (str[s->c] != '\0' && str[s->c] != '$' && str[s->c] != 32)
				s->newstr[s->dj++] = str[s->c++];
			check_dollar(s, s->dj, s->newstr, env);
		}
	}
}

void	ft_itog(void)
{
	char	*str;

	str = ft_itoa(g_globalv);
	write(1, str, ft_strlen(str));
	free(str);
}

void	check_dollar(t_token *s, int len, char *str, t_env *env)
{
	t_env	*curr;

	curr = env;
	(void)s;
	str[len] = '\0';
	while (curr)
	{
		if (ft_strcmp(curr->name, str) == 0)
		{
			write(1, curr->value, ft_strlen(curr->value));
			free(str);
			return ;
		}
		curr = curr->next;
	}
	write(1, "$", 1);
	write(1, str, ft_strlen(str));
	free(str);
}
