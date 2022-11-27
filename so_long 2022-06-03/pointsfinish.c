/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointsfinish.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:39:42 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/11 18:36:29 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exitchange(t_vars *vars)
{
	char	**finalmap;
	int		i;
	int		j;

	i = 0;
	j = 0;
	finalmap = *vars->map;
	while (i < vars->height)
	{
		while (j < vars->len)
		{
			if (finalmap[i][j] == 'e')
				finalmap[i][j] = 'E';
			j++;
		}
		j = 0;
		i++;
	}
}

void	finish(t_vars *vars)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = *vars->map;
	while (i < (*vars).height)
	{
		while (j < (*vars).len)
		{
			if (map[i][j] == 'c')
				break ;
			j++;
		}
		if (j < vars->len)
			break ;
		j = 0;
		i++;
	}
	if (i == 10 && j == 0)
		exitchange(vars);
}

void	printpoints(t_vars	vars)
{
	int		curcount;
	int		point;
	char	*s;
	char	a[3];

	curcount = points(&vars);
	s = "Points";
	a[0] = '-';
	point = vars.count - curcount;
	if (point <= 9)
		a[1] = point + '0';
	else if (point > 9 && point < 100)
	{
		a[0] = point / 10 + '0';
		a[1] = point % 10 + '0';
	}
	a[2] = '\0';
	mlx_string_put(vars.mlx_ptr, vars.win_ptr, 5, 5, 0xFFFFFF, s);
	mlx_string_put(vars.mlx_ptr, vars.win_ptr, 80, 5, 0xFFFFFF, a);
}

void	xpmtoimage(t_vars *wind, int *x, int *y)
{
	wind->img1 = mlx_xpm_file_to_image(wind->mlx_ptr, "image/wall.xpm", x, y);
	wind->img2 = mlx_xpm_file_to_image(wind->mlx_ptr, "image/coin.xpm", x, y);
	wind->img3 = mlx_xpm_file_to_image(wind->mlx_ptr, "image/person.xpm", x, y);
	wind->img4 = mlx_xpm_file_to_image(wind->mlx_ptr,
			"image/backwall.xpm", x, y);
	wind->img5 = mlx_xpm_file_to_image(wind->mlx_ptr, "image/door.xpm", x, y);
	wind->img6 = mlx_xpm_file_to_image(wind->mlx_ptr,
			"image/opendoor.xpm", x, y);
	wind->img7 = mlx_xpm_file_to_image(wind->mlx_ptr, "image/fire1.xpm", x, y);
	wind->img8 = mlx_xpm_file_to_image(wind->mlx_ptr, "image/fire2.xpm", x, y);
	wind->img9 = mlx_xpm_file_to_image(wind->mlx_ptr, "image/fire3.xpm", x, y);
}
