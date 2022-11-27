/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:33:16 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/11 19:57:05 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	keycodehook(int keycode, t_vars *vars, int i, int j)
{
	char	**map;

	map = *vars->map;
	if (keycode == 2 && map[i][j + 1] != '1')
		move_d(vars, i, j);
	else if (keycode == 0 && j > 0 && map[i][j - 1] != '1')
		move_a(vars, i, j);
	else if (keycode == 13 && i > 0 && map[i - 1][j] != '1')
		move_w(vars, i, j);
	else if (keycode == 1 && i < 9 && map[i + 1][j] != '1')
		move_s(vars, i, j);
	else if (keycode == 53)
	{
		mlx_destroy_image(vars->mlx_ptr, vars->win_ptr);
		exit(1);
	}
}

int	ft_close(int key, t_vars *vars)
{
	(void) key;
	(void) vars;
	exit(1);
	return (0);
}

int	key_hook(int keycode, t_vars *vars)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = *vars->map;
	while (i < vars->height)
	{
		while (j < vars->len)
		{
			if (map[i][j] == 'p' || map[i][j] == 'Z')
				break ;
			j++;
		}
		if (j < vars->len)
			break ;
		j = 0;
		i++;
	}
	keycodehook(keycode, vars, i, j);
	finish(vars);
	maps(*vars, map);
	printpoints(*vars);
	return (0);
}

void	rip(t_vars *vars, int i, int j)
{
	int		time;
	char	**map;

	map = *vars->map;
	time = 0;
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img4, j * 50, i * 50);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img9, j * 50, i * 50);
	map[i][j] = 'k';
}

void	findperson(t_vars *vars)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = -1;
	map = *vars->map;
	while (i < vars->height)
	{
		while (++j < vars->len)
		{
			if (map[i][j] == 'p' || map[i][j] == 'Z')
				break ;
		}
		if (j < vars->len)
			break ;
		j = -1;
		i++;
	}
	if (j == -1 && i == vars->height)
	{
		while (j < 200000000)
			j++;
		exit(1);
	}
}
