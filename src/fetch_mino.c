/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_mino.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 09:38:47 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/13 09:38:49 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char		*fetch_helper(int nb)
{
	if (nb == 10)
		return ("###..#");
	if (nb == 11)
		return ("##....#....#");
	if (nb == 12)
		return ("#..###");
	if (nb == 13)
		return ("##...##");
	if (nb == 14)
		return ("#....#....#....#");
	if (nb == 15)
		return ("####");
	if (nb == 16)
		return ("##..##");
	if (nb == 17)
		return ("#....##....#");
	if (nb == 18)
		return ("##....##");
	if (nb == 19)
		return ("#...##...#");
	return (NULL);
}

char			*fetch_mino(int nb)
{
	char	*str;

	str = NULL;
	if (nb == 1)
		return ("##...#....#");
	if (nb == 2)
		return ("###....#");
	if (nb == 3)
		return ("#....#...##");
	if (nb == 4)
		return ("#....###");
	if (nb == 5)
		return ("#...###");
	if (nb == 6)
		return ("#....##...#");
	if (nb == 7)
		return ("###...#");
	if (nb == 8)
		return ("#...##....#");
	if (nb == 9)
		return ("#....#....##");
	if (nb > 9)
		str = fetch_helper(nb);
	return (str);
}
