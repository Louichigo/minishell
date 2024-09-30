/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:15:33 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/15 11:33:11 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_cmds(t_token *token, t_env *env, char **envp)
{
	int		fd_pipe_tmp;
	int		fd_pipe[2];
	int		exit_status;
	pid_t	fork_pid;

	fd_pipe_tmp = 0;
	while (token)
	{
		pipe(fd_pipe);
		fork_pid = fork();
		if (fork_pid == 0)
		{
			prep_fd(token, &fd_pipe_tmp, fd_pipe);
			exec_cmd(token, env, envp);
			exit(g_globalv);
		}
		close_fd(token, &fd_pipe_tmp, fd_pipe);
		token = token->next;
	}
	while (waitpid(-1, &exit_status, 0) > 0)
		;
	if (WIFEXITED(exit_status))
		g_globalv = WEXITSTATUS(exit_status);
}

void	prep_fd(t_token *token, int *fd_pipe_tmp, int *fd_pipe)
{
	close(fd_pipe[0]);
	if (token->fdread == 1)
		token->fdread = *fd_pipe_tmp;
	dup2(token->fdread, STDIN_FILENO);
	if (token->fdwrite >= 3)
		close(fd_pipe[1]);
	else if (!token->next)
		token->fdwrite = 1;
	else
		token->fdwrite = fd_pipe[1];
	dup2(token->fdwrite, STDOUT_FILENO);
}

void	close_fd(t_token *token, int *fd_pipe_tmp, int *fd_pipe)
{
	close(fd_pipe[1]);
	if (*fd_pipe_tmp >= 3)
		close(*fd_pipe_tmp);
	if (token->fdwrite >= 3)
		close(token->fdwrite);
	if (token->fdread >= 3)
		close(token->fdread);
	*fd_pipe_tmp = fd_pipe[0];
}
