/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 18:22:08 by lobertho          #+#    #+#             */
/*   Updated: 2023/07/11 19:08:04 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//afficher l'argument et si -n pas de retour a la ligne
// si echo avec dollar alors check et faire if_dollars puis gerer si -n
void	ft_echo(t_data *s)
{
	printf("%s", s->line);
	if (s->echon == 0)
		printf("\n");
}
//doit gerer les \\\\ correctement