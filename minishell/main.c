/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/23 18:25:16 by lobertho         ###   ########.fr       */
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
	//char *args[] = {"ls", "-la", NULL};

	tok = (t_token *)malloc(sizeof(t_token));
	if (!tok)
		return (-1);
	(void)argv;
	(void)argc;
	env = init_env(envp);
	signalsinit();
	//ft_env(env);
	//ft_export(env, "TEST", "42");
	//ft_unset(&env, "TERM_SESSION_ID");
	//exec_cmd(args, envp);
	//ft_exit(env);
	//ft_cd(env, "~");
	//ft_pwd();
	//ft_echo("test salut", 0);
	while (42)
	{
		if ((input = readline("minishell$ ")) == NULL)
			ft_exit(env); // ctrl+d = exit
		add_history(input);
		//parser(input, env);
		//ft_free(input);
	}
	rl_clear_history();
	return (0);
}