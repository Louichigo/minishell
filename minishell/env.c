/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:04:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/23 17:39:16 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//fonction qui creer les maillons de l'environnement
void	createnode(t_env **env, char *name, char *value)
{
	t_env *newvar = malloc(sizeof(t_env));

	newvar->name = ft_strdup(name);
	newvar->value = ft_strdup(value);
	newvar->previous = NULL;
	newvar->next = NULL;
	if (*env == NULL)
	{
		*env = newvar;
		return ;
	}
	t_env *curr = *env;
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = newvar;
	curr->next->previous = curr;
}

//initialisation de l'environnement 
t_env	*init_env(char **envp)
{
	t_env	*env;
	int		i;
	char	*name;
	char	*value;

	i = 0;
	env = NULL;
	while (envp[i])
	{
		name = ft_splitname(envp[i]);
		value = ft_splitvalue(envp[i]);
		createnode(&env, name, value);
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
	while (curr != NULL)
	{
		printf("%s=%s\n", curr->name, curr->value);
		curr = curr->next;
	}
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