/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:15:33 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/14 17:45:26 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	exec_cmds(t_token *token, t_env *env)
{
	int		fd_pipe_tmp;
	int		fd_pipe[2];
	pid_t	fork_pid;

	fd_pipe_tmp = 0;
	pipe(fd_pipe);
	fork_pid = fork();
	if (fork_pid == 0)
	{
		prep_fd(token, &fd_pipe_tmp, fd_pipe);
		exec_cmd(token, env);
		exit(g_globalv);
	}
	close_fd(token, &fd_pipe_tmp, fd_pipe);
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
