/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/14 16:24:55 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_globalv = 0;

void	checkarg(int argc)
{
	if (argc != 1)
	{
		printf("too many arguments\n");
		exit(0);
	}
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*input;

	(void)argv;
	checkarg(argc);
	env = init_env(envp);
	signalsinit();
	while (42)
	{
		init_termios();
		signalsinit();
		input = readline("minishell >> ");
		if (!input)
			ft_exit(NULL, 0);
		else if (input[0] == '\0' || fullspace(input) == 0)
			continue ;
		else
		{
			parser(input, env);
			add_history(input);
			free(input);
		}
	}
	return (g_globalv);
}
