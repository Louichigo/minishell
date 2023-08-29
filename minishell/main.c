/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/29 16:52:51 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_cmd(char **cmd, char **envp)
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
		if (execve(get_right_path(*cmd), cmd, envp) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_token	*tok;
	t_env	*env;
	char	*input;

	tok = (t_token *)malloc(sizeof(t_token));
	if (!tok)
		return (-1);
	(void)argv;
	(void)argc;
	env = init_env(envp);
	signalsinit();
	while (42)
	{
		//if ((input = readline("minishell >> ")) == NULL)
		//	ft_exit(env); // ctrl+d = exit
		input = readline("minishell >> ");
		if (input == NULL || input[0] == '\0')
			continue;
		parser(input, env);
		add_history(input);
		free(input);
	}
	free(input);
	clear_history();
	//free env
	return (0);
}
