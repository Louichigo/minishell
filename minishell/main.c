/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/31 14:31:43 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int globalv = 0;

void	exec_cmd(t_env *env, char **cmd, char **envp)
{
	int	pid = 0;
	int status = 0;

	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		kill(pid, SIGTERM);
	}
	else
	{
		if (execve(get_right_path(env, *cmd), cmd, envp) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*input;

	(void)argv;
	(void)argc;
	env = init_env(envp);
	init_termios();
	while (42)
	{
		/*if ((input = readline("minishell >> ")) == NULL)
			ft_exit(env);*/ // ctrl+d = exit
		signalsinit();
		input = readline("minishell >> ");
		if (input == NULL || input[0] == '\0')
			continue;
		parser(input, env);
		add_history(input);
		free(input);
	}
	return (globalv);
}
