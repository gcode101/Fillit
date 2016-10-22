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
#include <stdio.h>

static int 	erase(char *map, char c)
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

static int	next_piece(char *str, int i)
{
	int 	next;

	next = 1;
	while (str[i] && str[i++] != '#')
		next++;
	return (next);
}

static bool	insert(char *mino, char *map, int pos, char c)
{
	int 	i;
	int 	blocks;

	i = 0;
	blocks = 0;
	while (mino[i])
	{
		if (mino[i] == '#')
		{
			if (map[pos] && map[pos] == '.')
			{
				map[pos] = c;
				if (c == 'C')
					printf("c inserted here: %d\n", pos);				
				pos += next_piece(mino, i + 1);
				// printf("pos: %d\n", pos);
				blocks++;
			}
			else
			{
				if (c == 'C')
				{
					printf("pos where c fails: %d\n", pos);
					// printf("char: %c\n", c);
				}
				erase(map, c);
				return (FALSE);
			}
		}
		i++;
	}
	if (blocks == 4)
		return (TRUE);
	else
		return (FALSE);
}

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
	end = 19;
	c = 'A';
	count = minos_count(str);
	minos = split_minos(str);
	while (minos[i])
	{
		if (insert(minos[i], map, start, c))
		{
			i++;
			c++;
			start = 0;
			printf("%s\n%s\n", "map: ", map);
		}
		else if (start < end)
			start++;
		else
		{
			i--;
			start = erase(map, --c); //erase deletes all c characters and returns the position + 1 of the first one it found
			printf("start: %d char: %c\n", start, c);
		}
	}
	if (need_space(map, minos_count(str)))
	{
		times++;
		ft_memdel((void**)&map);
		map = mapit(str, TRUE, times);
		printf("got a new map bro\n");
		map = solver(str, map, times);
	}
	return (map);
}
