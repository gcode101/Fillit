/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 15:13:25 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/26 16:40:11 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fillit.h>

static int	map_size(char *map)
{
	int		i;
	int		ct;

	i = 0;
	ct = 0;
	while (map[i])
	{
		if (map[i] != '\n')
			ct++;
		i++;
	}
	return (ct);
}

static int	next_piece(char *str, char *map, int i)
{
	int		map_len;
	int		times;
	int		next;
	int		perfect_sq;
	int		j;

	j = 5;
	next = 1;
	times = 0;
	perfect_sq = 16;
	map_len = map_size(map);
	while (str[i] && str[i++] != '#')
		next++;
	while (perfect_sq < map_len)
	{
		perfect_sq = j++;
		perfect_sq *= perfect_sq;
		times++;
	}
	if (next > 1)
		next += times;
	return (next);
}

static bool	block_checker(int blocks)
{
	if (blocks == 4)
		return (TRUE);
	return (FALSE);
}

bool		insert(char *mino, char *map, int pos, char c)
{
	int		i;
	int		blocks;

	i = 0;
	blocks = 0;
	while (mino[i])
	{
		if (mino[i] == '#')
		{
			if (map[pos] && map[pos] == '.')
			{
				map[pos] = c;
				pos += next_piece(mino, map, i + 1);
				blocks++;
			}
			else
			{
				erase(map, c);
				return (FALSE);
			}
		}
		i++;
	}
	return (block_checker(blocks));
}
