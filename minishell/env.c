/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:04:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/13 17:45:10 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//creer l'environnement et y ajouter les variables deja presentent
t_env	*init_env(char **envp)
{
	t_env	*env;
	int		i;
	char	*name;
	char	*value;

	i = 0;
	(void)envp;
	env = (t_env *)malloc(sizeof(env));
	env->name = ft_strdup(ft_splitname(envp[i]));
	env->value = ft_strdup(ft_splitvalue(envp[i]));
	env->next = NULL;
	env->previous = NULL;
	i++;
	while (envp[i])
	{
		name = ft_splitname(envp[i]);
		value = ft_splitvalue(envp[i]);
		ft_export(env, name, value);
		free(name);
		free(value);
		i++;
	}
	return (env);
}

//afficher l'environnement
void	ft_env(t_env *env)
{
	t_env *curr = env;
	while (curr)
	{
		printf("%s=%s\n", curr->name, curr->value);		
		curr = curr->next;
	}
}

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

// recuperer la valeur de la variable voulue et l'afficher
void	if_dollar(t_env *env, char *str)
{
	t_env *curr = env;

	while (curr)
	{
		if (strcmp(curr->name, str) == 0)
		{
			printf("%s\n", curr->value);
			return ;
		}
		if (!curr->next) 
			break;
		curr = curr->next;
	}
}