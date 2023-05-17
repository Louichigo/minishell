/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/05/17 12:59:40 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
		if (execve("/usr/local/bin:", cmd, NULL) == -1)
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
		exec_cmd(s->lexer);
		ft_free(s->lexer);
	}
	return (0);
}