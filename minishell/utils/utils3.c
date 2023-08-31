/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgross <cgross@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 22:48:58 by lobertho          #+#    #+#             */
/*   Updated: 2023/08/31 13:02:18 by cgross           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*ft_putdollar(t_token *s, t_env *env, char *str, int len)
{
	char	*newstr;
	char	*dstr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dstr = NULL;
	newstr = malloc(sizeof(char) * len + 1);
	while (str[i])
	{
		if (str[i] == 36)
		{
			i++;
			while (str[i] != '\0' && str[i] != 32)
			{
				newstr[j++] = str[i++];
			}
			newstr[j] = '\0';
			break;
		}
		i++;
	}
	dstr = if_dollar(s, env, newstr);
	return (dstr);
}