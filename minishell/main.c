/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/22 19:15:11 by lobertho         ###   ########.fr       */
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
	t_data	*s;
	t_env	*env;
	//char *args[] = {"ls", "-l", "-a", "-F", NULL};

	s = (t_data *)malloc(sizeof(t_data));
	if (!s)
		return (-1);
	signalsinit();
	(void)argv;
	(void)argc;
	env = init_env(envp);
	//ft_unset(env, "TERM_SESSION_ID");
	//exec_cmd(args, envp);
	while (42)
	{
		if ((s->line = readline("minishell$ ")) == NULL)
			ft_exit(env); // ctrl+d = exit
		add_history(s->line);
		ft_lexer(s, env);
		ft_free(s->lexer);
	}
	return (0);
}