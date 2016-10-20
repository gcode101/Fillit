/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/19 09:34:51 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/19 09:34:52 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	square_root(int n)
{
	int		x;
	int		y;

	x = n;
	y = 1;
	while (x > y)
	{
		x = (x + y) / 2;
		y = n / x;
	}
	return (x);
}

static int	get_space(char *str)
{
	int		pieces_num;
	int		perfect_sq;
	int		i;

	i = 4;
	perfect_sq = 16;
	pieces_num = minos_count(str) * 4;
	while (perfect_sq < pieces_num)
	{
		perfect_sq = i;
		perfect_sq *= perfect_sq;
		if (perfect_sq < pieces_num)
			i++;
	}
	return (perfect_sq + (i - 1));
}

char		*mapit(char *str)
{
	char	*map;
	int		map_size;
	int		i;
	int		j;
	int		row_len;

	i = 0;
	j = 0;
	map_size = get_space(str);
	row_len = square_root(map_size);
	if (!(map = malloc(sizeof(char) * (map_size) + 1)))
		return (NULL);
	map[map_size] = '\0';
	while (map_size--)
	{
		if (j++ == row_len)
		{
			map[i++] = '\n';
			j = 0;
		}
		else
			map[i++] = '.';
	}
	return (map);
}
