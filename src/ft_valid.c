/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 22:13:52 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/13 13:04:30 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static bool		check_level1(char *str, int i, int col, int row)
{
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '#' && str[i] != '\n')
			return (false);
		if (str[i] == '\n')
		{
			if (col != 4 || ((str[i + 1] == '\n' ||
					str[i + 1] == '\0') && row > 4))
				return (false);
			if (str[i + 1] != '\n')
			{
				col = 0;
				row++;
			}
			if (str[i + 1] == '\n')
				row = 0;
			if (str[i + 1] == '\n' && str[i + 2] == '\n')
				return (false);
		}
		else
			col++;
		i++;
	}
	return (true);
}

static bool		valid_pattern(char *mino)
{
	int		pattern;
	int		i;

	i = 0;
	pattern = 19;
	while (mino[i])
	{
		if (mino[i] == '\n')
			mino[i] = '.';
		i++;
	}
	mino = ft_trimfront(mino, '.');
	mino = ft_trimend(mino, '.');
	while (pattern)
	{
		if (ft_strcmp(mino, fetch_mino(pattern)) == 0)
			return (true);
		pattern--;
	}
	return (false);
}

bool			ft_valid(char *str)
{
	int		i;
	int		col;
	int		row;
	char	**minos;
	int		index;

	i = 0;
	col = 0;
	row = 1;
	index = 0;
	if (!str || ft_strlen(str) == 0 || !check_level1(str, i, col, row))
		return (false);
	if (!(minos = split_minos(str)))
		return (false);
	while (minos[i])
	{
		if (!valid_pattern(minos[i]))
			return (false);
		i++;
	}
	ft_memdel((void**)minos);
	return (true);
}
