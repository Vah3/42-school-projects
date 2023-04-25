/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:46:56 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/18 16:24:02 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_header.h"

void	initialize_struct(t_game *game)
{
	game->ceil_floor.ceil.blue = -1;
	game->ceil_floor.ceil.green = -1;
	game->ceil_floor.ceil.red = -1;
	game->ceil_floor.floor.blue = -1;
	game->ceil_floor.floor.green = -1;
	game->ceil_floor.floor.red = -1;
	game->directions.east.path_to_xpm = NULL;
	game->directions.west.path_to_xpm = NULL;
	game->directions.north.path_to_xpm = NULL;
	game->directions.south.path_to_xpm = NULL;
	game->map = NULL;
	game->player.face_to = 0;
	game->player.x = -1;
	game->player.y = -1;
	game->size_of_map = -1;
}

void	print_struct_arguments(t_game	*game)
{
	int	i;

	i = -1;
	printf("NO          -> %s\n", game->directions.north.path_to_xpm);
	printf("SO          -> %s\n", game->directions.south.path_to_xpm);
	printf("WE          -> %s\n", game->directions.west.path_to_xpm);
	printf("EA          -> %s\n", game->directions.east.path_to_xpm);
	printf("floor red   -> %d\n", game->ceil_floor.floor.red);
	printf("floor green -> %d\n", game->ceil_floor.floor.green);
	printf("floor blue  -> %d\n", game->ceil_floor.floor.blue);
	printf("ceil red    -> %d\n", game->ceil_floor.ceil.red);
	printf("ceil green  -> %d\n", game->ceil_floor.ceil.green);
	printf("ceil blue   -> %d\n", game->ceil_floor.ceil.blue);
	printf("player face_to   -> %c\n", game->player.face_to);
	printf("player x   -> %f\n", game->player.x);
	printf("player y   -> %f\n", game->player.y);
	printf("-------------------------------------------------\n");
	while (game->map[++i])
		printf("%s|\n", game->map[i]);
}

void	clear_struct(t_game *game)
{
	if (game->directions.north.path_to_xpm)
		free(game->directions.north.path_to_xpm);
	if (game->directions.south.path_to_xpm)
		free(game->directions.south.path_to_xpm);
	if (game->directions.west.path_to_xpm)
		free(game->directions.west.path_to_xpm);
	if (game->directions.east.path_to_xpm)
		free(game->directions.east.path_to_xpm);
	if (game->map)
		free_after_split(game->map);
	if (game->file)
		free_after_split(game->file);
	game->directions.north.path_to_xpm = NULL;
	game->directions.south.path_to_xpm = NULL;
	game->directions.west.path_to_xpm = NULL;
	game->directions.east.path_to_xpm = NULL;
	game->map = NULL;
	game->file = NULL;
}

int	main(int argc, char **argv)
{
	t_game			game;
	t_player_set	player;

	initialize_struct(&game);
	if (validation_of_file(&game, argv[1], argc))
		return (1);
	player.game = game;
	if (inits(&player) == 1)
		return (0);
	ft_ray_cast(&player);
	mlx_hook(player.d_mlx.win, 2, 0, set_true, &player);
	mlx_hook(player.d_mlx.win, 3, 0, ft_close, &player);
	mlx_hook(player.d_mlx.win, 17, 0, ft_closing, &player);
	mlx_loop(player.d_mlx.mlx);
	return (0);
}
