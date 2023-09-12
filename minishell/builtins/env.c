/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:04:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/12 18:28:17 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	createnode(t_env **env, char *name, char *value)
{
	t_env	*newvar;
	t_env	*curr;

	curr = *env;
	newvar = malloc(sizeof(t_env));
	newvar->name = ft_strdup(name);
	newvar->value = ft_strdup(value);
	newvar->previous = NULL;
	newvar->next = NULL;
	if (*env == NULL)
	{
		*env = newvar;
		return ;
	}
	while (curr->next != NULL)
	{
		curr = curr->next;
	}
	curr->next = newvar;
	curr->next->previous = curr;
}

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

int	ft_env(t_env **env, t_token *s)
{
	t_env	*curr;

	curr = *env;
	if (s->arg[0])
		return (1);
	while (curr != NULL)
	{
		if (curr->value != NULL)
			printf("%s=%s\n", curr->name, curr->value);
		curr = curr->next;
	}
	return (0);
}
