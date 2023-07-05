/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 14:26:30 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/05 15:35:02 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*int	is_builtin(char *command)
{
	if (ft_strcmp(command, "echo") == 0)
		return (1);
	if (ft_strcmp(command, "pwd") == 0)
		return (1);
	if (ft_strcmp(command, "ls") == 0)
		return (1);
	if (ft_strcmp(command, "cd") == 0)
		return (1);
	if (ft_strcmp(command, "export") == 0)
		return (1);
	if (ft_strcmp(command, "unset") == 0)
		return (1);
}

int	exec_builtin(char **tokens, t_data *s)
{
	int	result;

	result = 0;
	if (ft_strcmp(tokens[0], "echo") == 0)
		result = ft_echo(tokens);
	if (ft_strcmp(tokens[0], "pwd") == 0)
		result = ft_pwd(tokens);
	if (ft_strcmp(tokens[0], "ls") == 0)
		result = ft_ls(tokens);
	if (ft_strcmp(tokens[0], "cd") == 0)
		result = ft_cd(tokens);
	if (ft_strcmp(tokens[0], "export") == 0)
		result = ft_export(tokens);
	if (ft_strcmp(tokens[0], "unset") == 0)
		result = ft_unset(tokens);
}

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
*/

void	ft_unset(t_env *env, char *name)
{
	t_env *curr = env;

	while (curr)
	{
		if (ft_strcmp(curr->name, name) == 0)
		{
			if (!curr->previous)
			{
				curr->next->previous = NULL;
				t_env *temp = curr;
				curr = curr->next;
				free(temp->name);
				free(temp->value);
				temp = NULL;
				free(temp);
				return;
			}
			else if (!curr->next)
				curr->previous->next = NULL;
			else
			{
				curr->previous->next = curr->next;
				curr->next->previous = curr->previous;
			}
			free(curr->value);
			free(curr->name);
			curr = NULL;
			free(curr);
			return;
		}
		if (!curr->next)
			break;
		curr = curr->next;
	}	
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

void	ft_env(t_env *env)
{
	t_env *curr = env;
	while (curr)
	{
		printf("%s=%s\n", curr->name, curr->value);		
		curr = curr->next;
	}
}