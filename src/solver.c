/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 09:18:45 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/20 15:08:15 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*solver(char *str, char *map, int times)
{
	int		i;
	int 	start;
	int 	end;
	int 	count;
	char 	c;
	char	**minos;

	i = 0;
	start = 0;
	end = ft_strlen(map);
	c = 'A';
	count = minos_count(str);
	minos = split_minos(str);
	ft_putendl("Waiting for reply....");
	while (minos[i])
	{
		if (insert(minos[i], map, start, c))
		{
			i++;
			c++;
			start = 0;
		}
		else if (start < end)
			start++;
		else
		{
			i--;
			if (i == -1)
				break;
			start = erase(map, --c);
		}
	}
	if (need_space(map, count))
	{
		times++;
		ft_memdel((void**)&map);
		map = mapit(str, TRUE, times);
		map = solver(str, map, times);
	}
	ft_putendl("Done");
	return (map);
}
