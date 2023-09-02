/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:24:52 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/02 15:54:08 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**get_all_path(t_env *env) //getenv path and splits it
{
	char **all_paths;
   
	(void)env;
	all_paths = ft_split(find_var(env, "PATH"), ':');
	if (all_paths == NULL)
	{
		ft_free(all_paths);
		return (NULL);
	}
	else
		return (all_paths);
}

//finds right path for cmd, returns cmd if absolute path is found in env
char *get_right_path(t_env *env, char *cmd)
{
	int     i;
	char    *temp;
	char	**all_paths;
	char    *path;

	i = -1;
	all_paths = get_all_path(env);
	while (all_paths && all_paths[++i])
	{
		temp = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		if (access(path, X_OK) != -1 || access(cmd, X_OK) != -1)
		{
			free(temp);
			ft_free(all_paths);
			if (access(cmd, X_OK) != -1)
				return (cmd);
			return (path);
		}
		free(path);
		free(temp);
	}
	ft_free(all_paths);
	return (NULL);
}
