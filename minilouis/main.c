/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/05/17 16:22:26 by lobertho         ###   ########.fr       */
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
	int int_mode = 1;

	s = (t_data *)malloc(sizeof(t_data));
	if (!s)
		return (-1);
	s->history_count = 0;
	while (int_mode)
	{
		int_mode = isatty(STDIN_FILENO);
		if (int_mode == 1)
		{
			write(STDOUT_FILENO, "minishell$ ", 11);
			s->line = readline("");
			add_command_to_history(s);
			ft_lexer(s);
			//exec_cmd(s->lexer);
			ft_free(s->lexer);
		}
	}
	return (0);
}