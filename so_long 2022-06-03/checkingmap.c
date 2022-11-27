/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 15:41:35 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/11 19:44:34 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	freefunc(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	while (--i >= 0)
	{
		free(map[i]);
		i--;
	}
}

void	exitstatus(char **map, char c)
{
	if (c == 'a')
	{
		write(1, "Map is incorrect\n", 17);
		freefunc(map);
		exit(1);
	}
	else if (c == 'b')
	{
		write(1, "There is problem with map\n", 26);
		freefunc(map);
		exit(1);
	}
	else if (c == 'c')
	{
		write(1, "NOT Rectangular\n", 17);
		freefunc(map);
		exit(1);
	}
}

void	checkmemb(char **map)
{
	int	memb[5];

	memb[3] = -1;
	memb[4] = -1;
	memb[0] = 0;
	memb[1] = 0;
	memb[2] = 0;
	while (map[++memb[3]])
	{
		while (map[memb[3]][++memb[4]])
		{
			if (map[memb[3]][memb[4]] == 'c')
				memb[0]++;
			else if (map[memb[3]][memb[4]] == 'e')
				memb[1]++;
			else if (map[memb[3]][memb[4]] == 'p')
				memb[2]++;
			else if (map[memb[3]][memb[4]] != '0' &&
						map[memb[3]][memb[4]] != '1')
				exitstatus(map, 'a');
		}
		memb[4] = -1;
	}
	if (memb[2] != 1 || memb[1] < 1 || memb[0] < 1)
		exitstatus(map, 'b');
}

void	checkwalls(char **map)
{
	int	j;
	int	i;

	j = -1;
	i = 0;
	while (map[0][++j])
		checker(map, i, j);
	j--;
	while (map[i])
	{
		checker(map, i, j);
		i++;
	}
	i--;
	while (j > 0)
	{
		checker(map, i, j);
		j--;
	}
	j = 0;
	while (i > 0)
	{
		checker(map, i, j);
		i--;
	}
}

void	checkmap(char **map, int len, int height)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (height < 3)
		exitstatus(map, 'c');
	while (map[i])
	{
		while (map[i][j])
			j++;
		if (j != len)
			exitstatus(map, 'c');
		j = 0;
		i++;
	}
	i = 0;
	checkmemb(map);
	checkwalls(map);
}
