/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:04:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/29 17:11:24 by lobertho         ###   ########.fr       */
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
void	ft_env(t_env *env, t_token *s)
{
	t_env *curr = env;

	if (s->arg[0])
	{
		perror("error");
		return ;
	}
	while (curr != NULL)
	{
		printf("%s=%s\n", curr->name, curr->value);
		curr = curr->next;
	}
}

char	*if_dollar(t_token *s, t_env *env, char *str)
{
	t_env *curr = env;

	s->dollartemp = 0;
	while (curr)
	{
		if (strcmp(curr->name, str) == 0)
		{
			free(str);
			str = NULL;
			str = ft_strdup(curr->value);
			s->dollartemp = 1;
			return (str);
		}
		if (!curr->next) 
			break;
		curr = curr->next;
	}
	return (str);
}