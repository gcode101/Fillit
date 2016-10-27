/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcortina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/09 12:01:48 by gcortina          #+#    #+#             */
/*   Updated: 2016/10/26 17:08:08 by hehuang          ###   ########.fr       */
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
# include <stdbool.h>
# include "libft.h"
# define BUF_SIZE 4096
# define TETRIMINO 20

char			*ft_rdfile(char *file);
bool			ft_valid(char *str);
char			*fetch_mino(int nb);
int				minos_count(char *str);
char			*mapit(char *str, bool more_space, int times);
char			**split_minos(char *str);
char			*solver(char *str, char *map, int times);
char			*ft_concat(char *s1, char *s2);
bool			need_space(char *str, int count);
bool			insert(char *mino, char *map, int pos, char c);
int				erase(char *map, char c);
#endif
