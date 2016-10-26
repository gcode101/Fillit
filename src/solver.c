/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 09:18:45 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/26 16:17:41 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	insert_minos(char *str, char *map, char c, int start)
{
	int		i;
	int		end;
	char	**minos;

	i = 0;
	end = ft_strlen(map);
	minos = split_minos(str);
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
				break ;
			start = erase(map, --c);
		}
	}
}

char		*solver(char *str, char *map, int times)
{
	int		start;
	int		count;
	char	c;

	start = 0;
	c = 'A';
	count = minos_count(str);
	ft_putendl("Waiting for reply....");
	insert_minos(str, map, c, start);
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
