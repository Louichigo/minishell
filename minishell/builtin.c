/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:26:30 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/13 17:47:05 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(void)
{
	char *cwd;

	cwd = malloc(PATH_MAX);
	if (getcwd(cwd, PATH_MAX) != NULL)
		printf("%s\n", cwd);
	else
		perror("getcwd()");
	free(cwd);
}

void	ft_exit(void)
{
	exit(EXIT_SUCCESS);
}

void	ft_export(t_env *env, char *name, char *value)
{
	t_env *curr = env;

	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			strcpy(curr->value, value);
			return ;
		}
		if (!curr->next) 
			break;
		curr = curr->next;
	}
	t_env *new_var = (t_env *)malloc(sizeof(t_env));
	new_var->name = ft_strdup(name);
	new_var->value = ft_strdup(value);
	new_var->next = NULL;
	curr->next = new_var;
	curr->next->previous = curr;
}