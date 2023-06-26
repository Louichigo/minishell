/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/06/26 20:56:26 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*void	exec_cmd(char **cmd)
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
		if (execve(PATH, cmd, NULL) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	}
}*/

void	handler(int num)
{
	if (num == SIGINT)   //sigint = ctrl+C = affiche un nouveau prompt
	{
		//rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
	else if (num == SIGQUIT)  //sigquit = ctrl+\ ne rien faire 
	{
		rl_on_new_line();
		rl_redisplay();
		return ;
	}
}

void	signalsinit(void)
{
	signal(SIGINT, handler);
	signal(SIGQUIT, handler);
}

int	main(int argc, char **argv, char **envp)
{
	t_data	*s;
	t_env	*env;

	s = (t_data *)malloc(sizeof(t_data));
	if (!s)
		return (-1);
	signalsinit();
	(void)argv;
	(void)argc;
	env = init_env(envp);
	while (42)
	{
		if ((s->line = readline("minishell$ ")) == NULL)
		{
			printf("\nexit\n");
			exit(EXIT_SUCCESS);
		}
		add_history(s->line);
		//ft_env(env);
		ft_lexer(s);
		ft_free(s->lexer);
	}
	return (0);
}