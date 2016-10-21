/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_minos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 12:22:41 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/21 11:23:58 by hehuang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

bool	still_in_mino(char *str, int i)
{
	if ((str[i] == '\n' && str[i + 1] == '\n') || str[i] == '\0')
		return (FALSE);
	return (TRUE);
}

char	**split_minos(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**minos;

	i = 0;
	k = 0;
	if (!(minos = (char**)malloc(sizeof(char*) * (minos_count(str)) + 1)))
		return (NULL);
	while (str[i])
	{
		if (!(minos[k] = malloc(sizeof(char) * (TETRIMINO) + 1)))
			return (NULL);
		j = 0;
		while (still_in_mino(str, i))
			minos[k][j++] = str[i++];
		minos[k][j] = '\0';
		k++;
		i += 2;
	}
	minos[k] = NULL;
	return (minos);
}
