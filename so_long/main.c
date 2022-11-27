/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:15:42 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/11 19:27:12 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	char	**map;
	int		len;
	int		height;

	if (argc == 2)
	{
		map = init_map(argv[1]);
		if (!map)
		{
			write(1, "Map is empty", 12);
			exit(1);
		}
		calculate(&len, &height, map);
		checkmap(map, len, height);
		window_image(len, height, map);
	}
	return (0);
}
