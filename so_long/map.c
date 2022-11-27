/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:20:19 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/11 19:32:36 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**init_map(char *filename)
{
	char	*lin_matrix;
	char	buf[6];
	char	**map;
	int		fd;
	int		i;

	lin_matrix = NULL;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 1;
	while (i > 0)
	{
		i = read(fd, buf, 5);
		buf[i] = '\0';
		if (i == 0 && !lin_matrix)
			return (0);
		if (!lin_matrix)
			lin_matrix = ft_strdup(buf);
		else
			lin_matrix = ft_strjoin(lin_matrix, buf);
	}
	map = ft_split(lin_matrix, '\n');
	free(lin_matrix);
	return (map);
}

void	mapimage(t_vars wind, int c, int b, char **map)
{
	if (map[b][c] == '0')
		mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
			wind.img4, c * 50, b * 50);
	else if (map[b][c] == '1')
		mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
			wind.img1, c * 50, b * 50);
	else if (map[b][c] == 'c')
		map_c(wind, c, b);
	else if (map[b][c] == 'p')
		map_p(wind, c, b);
	else if (map[b][c] == 'e')
	{
		mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
			wind.img4, c * 50, b * 50);
		mlx_put_image_to_window(wind.mlx_ptr, wind.win_ptr,
			wind.img5, c * 50, b * 50);
	}
	else if (map[b][c] == 'Z')
		map_z(wind, c, b);
	else if (map[b][c] == 'E')
		map_e(wind, c, b);
}
