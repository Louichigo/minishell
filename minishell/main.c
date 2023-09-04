/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/04 16:38:40 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int globalv = 0;

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*input;

	(void)argv;
	(void)argc;
	env = init_env(envp);
	init_termios();
	signalsinit();
	while (42)
	{
		/*if ((input = readline("minishell >> ")) == NULL)
			ft_exit(env);*/ // ctrl+d = exit
		input = readline("minishell >> ");
		if (input == NULL || input[0] == '\0' || fullspace(input) == 0)
			continue;
		parser(input, env);
		add_history(input);
		free(input);
	}
	return (globalv);
}
