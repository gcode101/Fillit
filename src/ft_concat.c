/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/28 16:02:56 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/09 21:28:18 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_concat(char *s1, char *s2)
{
	char *result;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (result)
	{
		ft_strcpy(result, s1);
		ft_strcat(result, s2);
	}
	return (result);
}
