/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 20:23:02 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/11 19:09:32 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	maps(t_vars wind, char **map)
{
	int	b;
	int	c;

	c = 0;
	b = 0;
	while (b < wind.height)
	{
		while (c < wind.len)
		{
			mapimage(wind, c, b, map);
			c++;
		}
		c = 0;
		b++;
	}
}

int	points(t_vars *vars)
{
	char	**map;
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	map = *vars->map;
	while (i < vars->height)
	{
		while (j < vars->len)
		{
			if (map[i][j] == 'c')
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	anim(t_vars *vars)
{
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img7, (vars->len / 2 - 5) * 50, vars->height / 2 * 50);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
		vars->img7, (vars->len / 2) * 50, vars->height / 2 * 50);
}

int	animation(t_vars *vars)
{
	static int	i;

	findperson(vars);
	if (i == 0)
	{
		animutils(vars);
		anim(vars);
	}
	else if (i == 10000)
	{
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img8, (vars->len / 2 - 5) * 50, vars->height / 2 * 50);
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img8, (vars->len / 2) * 50, vars->height / 2 * 50);
	}
	else if (i == 20000)
	{
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img9, (vars->len / 2 - 5) * 50, vars->height / 2 * 50);
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img9, (vars->len / 2) * 50, vars->height / 2 * 50);
		i = 0;
	}
	i++;
	return (0);
}

void	window_image(int len, int height, char **map)
{
	t_vars	wind;
	int		x;
	int		y;

	wind.mlx_ptr = mlx_init();
	wind.win_ptr = mlx_new_window(wind.mlx_ptr, len * 50,
			height * 50, "so_long");
	xpmtoimage(&wind, &x, &y);
	wind.len = len;
	wind.height = height;
	wind.map = &map;
	maps(wind, map);
	wind.count = points(&wind);
	mlx_hook(wind.win_ptr, 3, 0, key_hook, &wind);
	mlx_hook(wind.win_ptr, 17, 0, ft_close, &wind);
	mlx_loop_hook(wind.mlx_ptr, animation, &wind);
	mlx_loop(wind.mlx_ptr);
}
