/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:46:51 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/18 11:51:31 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*find_var(t_env *env, char *name)
{
	t_env	*curr;

	curr = env;
	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			return (curr->value);
		}
		if (!curr->next)
		{
			return (NULL);
		}
		curr = curr->next;
	}
	return (NULL);
}

int	ft_cd(t_env *env, char *str)
{
	char	*cwd;

	cwd = malloc(PATH_MAX);
	getcwd(cwd, PATH_MAX);
	if (cd_cond(env, str) != 0)
	{
		free(cwd);
		return (1);
	}
	ft_export(env, "OLDPWD", cwd);
	free(cwd);
	cwd = malloc(PATH_MAX);
	getcwd(cwd, PATH_MAX);
	ft_export(env, "PWD", cwd);
	free(cwd);
	return (0);
}

int	cd_cond(t_env *env, char *str)
{
	if ((ft_strcmp(str, "~") == 0) || (ft_strcmp(str, "") == 0))
	{
		if (chdir(find_var(env, "HOME")) != 0)
		{
			perror("minishell: $HOME error");
			return (1);
		}
	}
	else if (ft_strcmp(str, "-") == 0)
	{
		if (chdir(find_var(env, "OLDPWD")) != 0)
		{
			perror("minishell: $OLDPWD error");
			return (1);
		}
	}
	else if (chdir(str) != 0)
	{
		perror("minishell: cd");
		return (1);
	}
	return (0);
}

int	ft_cd_parse(t_token *s, t_env *env)
{
	char	*str;
	int		ret;

	ret = 0;
	if (s->arg[0] == NULL)
	{
		ft_cd(env, "");
		return (EXIT_SUCCESS);
	}
	str = ft_dechar(s->arg);
	ret = ft_cd(env, str);
	free(str);
	return (ret);
}
