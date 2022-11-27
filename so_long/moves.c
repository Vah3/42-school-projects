/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:24:10 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/11 19:47:47 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_vars *vars, int i, int j)
{
	char	**map;

	map = *vars->map;
	if (map[i][j] == 'Z')
		map[i][j] = 'e';
	else
		map[i][j] = '0';
	if (map[i - 1][j] == 'e')
			map[i - 1][j] = 'Z';
	else if (map[i - 1][j] == 'E')
		exit (1);
	else if (map[i - 1][j] == 'T')
		rip(vars, i, j);
	else if (map [i - 1][j] != 'k')
		map[i - 1][j] = 'p';
}

void	move_s(t_vars *vars, int i, int j)
{
	char	**map;

	map = *vars->map;
	if (map[i][j] == 'Z')
		map[i][j] = 'e';
	else
		map[i][j] = '0';
	if (map[i + 1][j] == 'e')
			map[i + 1][j] = 'Z';
	else if (map[i + 1][j] == 'E')
		exit(1);
	else if (map[i + 1][j] == 'T')
		rip(vars, i, j);
	else if (map [i + 1][j] != 'k')
		map[i + 1][j] = 'p';
}

void	move_a(t_vars *vars, int i, int j)
{
	char	**map;

	map = *vars->map;
	if (map[i][j] == 'Z')
		map[i][j] = 'e';
	else
		map[i][j] = '0';
	if (map[i][j - 1] == 'e')
		map[i][j - 1] = 'Z';
	else if (map[i][j - 1] == 'E')
		exit(1);
	else if (map[i][j - 1] == 'T')
		rip(vars, i, j);
	else if (map[i][j - 1] != 'k')
		map[i][j - 1] = 'p';
}

void	move_d(t_vars *vars, int i, int j)
{
	char	**map;

	map = *vars->map;
	if (map[i][j] == 'Z')
		map[i][j] = 'e';
	else if (map[i][j] != 'k')
		map[i][j] = '0';
	if (map[i][j + 1] == 'e')
		map[i][j + 1] = 'Z';
	else if (map[i][j + 1] == 'E')
		exit(1);
	else if (map[i][j + 1] == 'T')
		rip(vars, i, j);
	else if (map[i][j + 1] != 'k')
		map[i][j + 1] = 'p';
}
