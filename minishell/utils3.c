/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lobertho <lobertho@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:48:58 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/28 23:07:23 by lobertho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_putdollar(t_env *env, char *str, int len)
{
	char	*newstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	newstr = malloc(sizeof(char) * len + 1);
	while (str[i])
	{
		if (str[i] == 36)
		{
			i++;
			while (str[i] != '\0' || str[i] != 32)
			{
				newstr[j++] = str[i++];
			}
			newstr[j] = '\0';
			break;
		}
		i++;
	}
	return (if_dollar(env, newstr));
}