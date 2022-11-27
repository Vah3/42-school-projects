/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:06:09 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/11 19:42:49 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calculate(int *len, int *height, char **map)
{
	*len = 0;
	*height = 0;
	while (map[0][*len])
		(*len)++;
	while (map[*height])
		(*height)++;
}

void	checker(char **map, int i, int j)
{
	if (map[i][j] != '1')
	{
		write(1, "There is problem with walls", 27);
		freefunc(map);
		exit(1);
	}
}

void	putnbr(int key)
{
	char	s;

	if (key < 10)
	{
		s = key + '0';
		write(1, &s, 1);
		return ;
	}
	else
		putnbr(key / 10);
	putnbr(key % 10);
}
