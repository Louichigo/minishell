/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:15:33 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/05 14:21:43 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/*void	close_fd(t_pip *pip)
{
	close(pip->pipe[0]);
	close(pip->pipe[1]);
	close(pip->file[0]);
	close(pip->file[1]);
}

void	exec_cmd1(t_pip *p, char **av, char **envp)
{
	p->cmd[0] = ft_split(av[2], ' ');
	p->path[0] = get_right_path(envp, p->cmd[0][0]);
	if (!p->path[0])
		noexec(av[2]);
	dup2(p->pipe[1], STDOUT_FILENO);
	dup2(p->file[0], STDIN_FILENO);
	close_fd(p);
	execve(p->path[0], p->cmd[0], envp);
}

void	exec_cmd2(t_pip *p, char **av, char **envp)
{
	p->cmd[1] = ft_split(av[3], ' ');
	p->path[1] = get_right_path(envp, p->cmd[1][0]);
	if (!p->path[1])
		noexec(av[3]);
	dup2(p->pipe[0], STDIN_FILENO);
	dup2(p->file[1], STDOUT_FILENO);
	close_fd(p);
	execve(p->path[1], p->cmd[1], envp);
}

int	main(int ac, char **av, char **envp)
{

	if (ac != 5)
		error("usage: $> ./pipex file1 cmd1 cmd2 file2\n");
	p.file[0] = open(av[1], O_RDONLY);
	if (p.file[0] == -1)
		error(av[1]);
	p.file[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (p.file[1] == -1)
		error(av[4]);
	if (pipe(p.pipe) == -1)
		error("error with pipe();\n");
	p.pid[0] = fork();
	if (p.pid[0] == 0)
		exec_cmd1(&p, av, envp);
	p.pid[1] = fork();
	if (p.pid[1] == 0)
		exec_cmd2(&p, av, envp);
	close_fd(&p);
	waitpid(p.pid[0], NULL, 0);
	waitpid(p.pid[1], &p.exit, 0);
	if (WIFEXITED(p.exit))
		return (WEXITSTATUS(p.exit));
	return (0);*/