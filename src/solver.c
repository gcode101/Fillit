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

static int 	erase(char *map, char c)
{
	int 	i;
	int 	blocks;
	int 	pos;

	i = 0;
	blocks = 0;
	pos = 0;
	while (map[i] && blocks < 4)
	{
		if (map[i] == c)
		{
			map[i] = '.';
			blocks++;
		}
		if (blocks == 1)
			pos = i + 1;
		i++;
	}
	return (pos);
}

static int	next_piece(char *str, int i)
{
	int 	next;

	next = 1;
	while (str[i++] != '#')
		next++;
	return (next);
}

static bool	insert(char *mino, char *map, int pos, char c)
{
	int 	i;
	int 	blocks;

	i = 0;
	blocks = 0;
	while (mino[i] && map[pos])
	{
		if (mino[i] == '#')
		{
			if (map[pos] == '.')
			{
				map[pos] = c;
				pos += next_piece(mino, i + 1);
				blocks++;
			}
			else
				return (FALSE);
		}
		i++;
	}
	if (blocks == 4)
		return (TRUE);
	else
		return (FALSE);
}

char		*solver(char *str, char *map)
{
	int		i;
	int 	start;
	int 	end;
	char 	c;
	char	**minos;

	i = 0;
	start = 0;
	end = 19;
	c = 'A';
	minos = split_minos(str);
	while (minos[i])
	{
		if (insert(minos[i], map, start, c))
		{
			i++;
			c++;
			start = 0;
		}
		else if (start != end)
			start++;
		else
		{
			i--;
			start = erase(map, --c); //erase deletes all c characters and returns the position + 1 of the first one it found
		}
	}
	return (map);
}
