/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:17:49 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/28 21:56:34 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execution(t_token *s, t_env *env)
{
	if (is_builtin(s) == 1)
		exec_builtin(s, env);
	//else if (//dollar)	
	/*else
		exec_cmd(arg_all, envp);*/

}