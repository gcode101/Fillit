/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 12:01:48 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/09 14:39:00 by gcortina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "libft.h"
# define BUF_SIZE 4096
# define TRUE 1
# define FALSE 0
# define TETRIMINO 20

typedef int		bool;
char			*ft_rdfile(char *file);
bool			ft_valid(char *str);
char 			*fetch_mino(int nb);
int				minos_count(char *str);
char			*mapit(char *str);
char			**split_minos(char *str);
char			*solver(char *str, char *map);
char			*ft_concat(char *s1, char *s2);
#endif
