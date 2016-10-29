/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rdfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 20:59:07 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/20 15:44:15 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_rdfile(char *file)
{
	int			fd;
	int			ret;
	char		buf[BUF_SIZE + 1];
	char		*str;

	str = malloc(sizeof(char) * 1);
	if (!str)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd >= 0)
	{
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			buf[ret] = '\0';
			str = ft_concat(str, buf);
		}
		if (!ft_strlen(str))
			ft_putendl_fd("error", 2);
	}
	else
		ft_putendl_fd("error", 2);
	close(fd);
	return (str);
}
