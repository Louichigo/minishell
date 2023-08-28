/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:24:52 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/21 16:25:39 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_all_path() //getenv path and splits it
{
	char **all_paths;
   
	all_paths = ft_split(getenv("PATH"), ':');
	if (all_paths == NULL)
	{
		ft_free(all_paths);
		return (NULL);
	}
	else
		return (all_paths);
}

char *get_right_path(char *cmd) //finds right path for cmd
{
	int     i;
	char    *temp;
	char	**all_paths;
	char    *path;

	i = -1;
	all_paths = get_all_path();
	while (all_paths && all_paths[++i])
	{
		temp = ft_strjoin(all_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		if (access(path, X_OK) != -1)
		{
			free(temp);
			ft_free(all_paths);
			return (path);
		}
		free(path);
		free(temp);
	}
	ft_free(all_paths);
	return (NULL);
}