/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:15:33 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/06 15:48:03 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	noexec(char *name)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	ft_putstr_fd(name, STDERR_FILENO);
	ft_putstr_fd(": command not found\n", STDERR_FILENO);
	exit(127);
}

void	close_fd(t_token *pip)
{
	close(pip->file[0]);
	close(pip->file[1]);
}

void	exec_cmd1(t_token *p, t_env *env, char *cmd1)
{
	p->cmdd[0] = ft_split(cmd1, ' ');
	p->path[0] = get_right_path(env, p->cmdd[0][0]);
	if (!p->path[0])
		noexec(cmd1);
	dup2(p->file[1], STDOUT_FILENO);
	close_fd(p);
	execve(p->path[0], p->cmdd[0], NULL);
}

void	exec_cmd2(t_token *p, t_env *env, char *cmd2)
{
	p->cmdd[1] = ft_split(cmd2, ' ');
	p->path[1] = get_right_path(env, p->cmdd[1][0]);
	if (!p->path[1])
		noexec(cmd2);
	dup2(p->file[0], STDIN_FILENO);
	close_fd(p);
	execve(p->path[1], p->cmdd[1], NULL);
}

int	pipex(t_token *s, t_env *env, char *cmd1, char *cmd2)
{
	if (pipe(s->file) == -1)
		error("error with pipe();\n");
	s->pid[0] = fork();
	if (s->pid[0] == 0)
		exec_cmd1(s, env, cmd1);
	s->pid[1] = fork();
	if (s->pid[1] == 0)
		exec_cmd2(s, env, cmd2);
	close_fd(s);
	waitpid(s->pid[0], NULL, 0);
	waitpid(s->pid[1], NULL, 0);
	if (WIFEXITED(s->exit))
		return (WEXITSTATUS(s->exit));
	return (0);
}
