/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maping.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:35:16 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/11 18:58:00 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_z(t_vars wind, int c, int b)
{
	mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
		wind.img4, c * 50, b * 50);
	mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
		wind.img5, c * 50, b * 50);
	mlx_put_image_to_window(wind.mlx_ptr,
		wind.win_ptr, wind.img3, c * 50, b * 50);
}

void	map_e(t_vars wind, int c, int b)
{
	mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
		wind.img4, c * 50, b * 50);
	mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
		wind.img6, c * 50, b * 50);
}

void	map_c(t_vars wind, int c, int b)
{
	mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
		wind.img4, c * 50, b * 50);
	mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
		wind.img2, c * 50 + 14, b * 50 + 2);
}

void	map_p(t_vars wind, int c, int b)
{
	mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
		wind.img4, c * 50, b * 50);
	mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
		wind.img3, c * 50 + 14, b * 50);
}

void	animutils(t_vars *vars)
{
	char	**map;

	map = *vars->map;
	if (vars->len / 2 > 5 && map[vars->height / 2][vars->len / 2 - 5] == 'c')
		vars->count--;
	if (map[vars->height / 2][vars->len / 2] == 'c')
		vars->count--;
	if (vars->len / 2 > 5 && map[vars->height / 2][vars->len / 2 - 5] != 'T')
	{
		map[vars->height / 2][vars->len / 2 - 5] = 'T';
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img4, (vars->len / 2 - 5) * 50, vars->height / 2 * 50);
	}
	if (map[vars->height / 2][vars->len / 2] != 'T')
	{
		map[vars->height / 2][vars->len / 2] = 'T';
		mlx_put_image_to_window(vars->mlx_ptr, vars->win_ptr,
			vars->img4, vars->len / 2 * 50, vars->height / 2 * 50);
	}
}
