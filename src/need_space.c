/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   need_space.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 15:05:35 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/21 15:05:36 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

bool	need_space(char *str, int count)
{
	int		pieces;
	int		i;

	i = 0;
	pieces = count * 4;
	while (str[i])
	{
		if (str[i] != '.' && str[i] != '\n')
			pieces--;
		i++;
	}
	if (pieces)
		return (TRUE);
	return (FALSE);
}
