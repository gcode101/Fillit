/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 12:22:41 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/20 15:07:55 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**split_minos(char *str)
{
	int		i;
	int		j;
	char	**minos;
	char	elem;

	i = 0;
	j = 0;
	if (!(minos = (char**)malloc(sizeof(char*) * (minos_count(str)) + 1)))
		return (NULL);
	while (str[i])
	{
		if (!(elem = malloc(sizeof(char) * (TETRIMINO) + 1)))
			return (NULL);
		while (1)
		{
			elem[j++] = str[i++];
			if (str[i] == '\n' && str[i + 1] == '\n')
				break;
		}
		
		i++;
	}
	return (minos);
}
