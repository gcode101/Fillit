/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_next.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 14:11:08 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/27 14:11:10 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_next(char *map, int next)
{
	int		map_len;

	map_len = ft_strlen(map);
	if (map_len == 5 && next > 1)
		next -= 2;
	else if (map_len == 11 && next > 1)
		next -= 1;
	return (next);
}
