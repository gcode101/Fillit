/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 12:20:47 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/09 16:09:08 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	char	*str;
	char	*map;
	int		times;

	times = 0;
	if (argc != 2)
	{
		ft_putendl("usage: ./fillit [filename]");
		return (0);
	}
	str = ft_rdfile(argv[1]);
	if (ft_valid(str))
	{
		map = mapit(str, FALSE, times);
		ft_putendl("Waiting for reply...");
		map = solver(str, map, times);
		ft_putendl(map);
	}
	else
		ft_putendl("not valid");
	return (0);
}
