/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:22:08 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/22 17:57:13 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//afficher l'argument et si -n pas de retour a la ligne
// si echo avec dollar alors check et faire if_dollars puis gerer si -n
void	ft_echo(t_data *s, char *str, int echon)
{
	write(1, str, ft_strlen(s->line));
	if (echon == 0)
		write(1, "\n", 1);
}
//doit gerer les \\\\ correctement