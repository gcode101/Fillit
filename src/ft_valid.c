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
			return (FALSE);
		if (str[i] == '\n')
		{
			if (col != 4 || ((str[i + 1] == '\n' ||
					str[i + 1] == '\0') && row > 4))
				return (FALSE);
			if (str[i + 1] != '\n')
			{
				col = 0;
				row++;
			}
			if (str[i + 1] == '\n')
				row = 0;
			if (str[i + 1] == '\n' && str[i + 2] == '\n')
				return (FALSE);
		}
		else
			col++;
		i++;
	}
	return (TRUE);
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
			return (TRUE);
		pattern--;
	}
	return (FALSE);
}

bool			ft_valid(char *str)
{
	int		i;
	int		col;
	int		row;
	int		minos_total;
	char	*mino;

	i = 0;
	col = 0;
	row = 1;
	if (!str || ft_strlen(str) == 0 || !check_level1(str, i, col, row))
		return (FALSE);
	minos_total = minos_count(str);
	if (!(mino = malloc(sizeof(char) * (TETRIMINO) + 1)))
		return (FALSE);
	while (minos_total)
	{
		mino = ft_strncpy(mino, &str[i], TETRIMINO);
		if (!valid_pattern(mino))
			return (FALSE);
		i += TETRIMINO + 1;
		minos_total--;
	}
	free(mino);
	return (TRUE);
}
