/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:44:08 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/26 15:44:10 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

int		erase(char *map, char c)
{
	int 	i;
	int 	blocks;
	int 	pos;
	bool	is_off;

	i = 0;
	blocks = 0;
	pos = 0;
	is_off = TRUE;
	while (map[i] && blocks < 4)
	{
		if (map[i] == c)
		{
			map[i] = '.';
			blocks++;
		}
		if (blocks && is_off)
		{
			pos = i + 1;
			is_off = FALSE;
		}
		i++;
	}
	return (pos);
}
