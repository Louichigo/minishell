/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 16:51:06 by lobertho          #+#    #+#             */
/*   Updated: 2023/09/05 12:53:40 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int globalv = 0;

int	main(int argc, char **argv, char **envp)
{
	t_env	*env;
	char	*input;

	(void)argv; 
	if (argc != 1)
	{
		printf("invalid args,try ./minishell\n");
		return (1);
	}
	env = init_env(envp);
	init_termios();
	signalsinit();
	while (42)
	{
		input = readline("minishell >> ");
		if (!input)
			ft_exit(env, 0);
		else if (input[0] == '\0' || fullspace(input) == 0)
			continue;
		else
		{
			parser(input, env);
			add_history(input);
			free(input);
		}
	}
	return (globalv);
}
