/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/05/15 15:36:53 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_ablosute_path(char **cmd)
{
	char *path;
	char *bin;
	char **path_split;

	path = ft_strdup(getenv("PATH"));
	bin = NULL;
	path_split = NULL;

}

void	exec_cmd(char **cmd)
{
	pid_t	pid;
	int		status;

	status = 0;
	pid = 0;
	//on fork pour creer un processus enfant
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		//on fait attendre le processus parent jusqua ce que l enfant termine
		waitpid(pid, &status, 0);
		//on termine le processus enfant
		kill(pid, SIGTERM);
	}
	else
	{
		//le processus enfant execute la commande ou exit si ca echoue
		if (execve(cmd[0], cmd, NULL) == -1)
			perror("minishell");
		exit(EXIT_FAILURE);
	}
}

int	main(void)
{
	t_data *s;

	s = (t_data *)malloc(sizeof(t_data));
	if (!s)
		return (-1);
	while (42)
	{
		s->line = readline("minishell$ ");
		add_history(s->line);
		ft_lexer(s);
		get_absolute_path(s->lexer);
		if (s->lexer[0] == NULL)
			printf("Command not found\n");
		else
		exec_cmd(s->lexer);
	}
	return (0);
}