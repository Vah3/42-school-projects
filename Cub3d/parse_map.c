/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <edgghaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:51:13 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/18 13:23:45 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	assing_cube_side(t_game *game,
	char **splited_info, int *count_of_information)
{
	if (is_empty_keys_value(game, splited_info[0]))
	{
		if (is_valid_path(game, splited_info[1]))
			assign_direction(game, splited_info, count_of_information);
		else
		{
			free_after_split(splited_info);
			return (7);
		}
	}
	else
	{
		free_after_split(splited_info);
		return (6);
	}
	return (0);
}

int	assign_information(t_game *game,
	char **splited_info, int *count_of_information)
{
	int	error_code;

	error_code = 5;
	if (is_cubes_side(splited_info[0]) || is_surface(splited_info[0]))
	{
		error_code = 0;
		if (is_cubes_side(splited_info[0]))
		{
			error_code = assing_cube_side(game,
					splited_info, count_of_information);
			if (error_code)
				return (error_code);
		}
		else
		{
			if (can_assign(game, splited_info[0], &error_code)
				&& is_valid_color_codes(splited_info[1], &error_code))
			{
				if (!error_code)
					assign_rgb(game, splited_info, count_of_information);
			}
		}
	}
	free_after_split(splited_info);
	return (error_code);
}

int	start_first_part(t_game	*game, int *i, int count_of_information)
{
	char	**splited_info;
	int		error_code;

	error_code = 0;
	while ((game->file)[++(*i)] && count_of_information < 6)
	{
		splited_info = ft_split((game->file)[(*i)], ' ');
		if (splited_size(splited_info) == 0)
		{
			free_after_split(splited_info);
			continue ;
		}
		if (splited_size(splited_info) != 2)
		{
			free_after_split(splited_info);
			return (4);
		}
		error_code = assign_information(game, splited_info,
				&count_of_information);
		if (error_code)
			return (error_code);
	}
	if (count_of_information < 6)
		return (14);
	return (0);
}

int	start_second_part(t_game *game, int *i)
{
	skip_spaces_and_get_sizeof_map(game, i);
	if (game->size_of_map == 0)
		return (15);
	get_map_from_file(game, i, game->size_of_map + 2);
	if (!(game->map))
		return (16);
	if (there_is_empty_line_in_map(game->map, game->size_of_map))
		return (17);
	if (there_is_invalid_char(game->map))
		return (23);
	if (maps_up_and_down_is_not_correct(game->map, game->size_of_map))
		return (18);
	if (left_wall_is_not_correct(game->map))
		return (19);
	if (right_wall_is_not_correct(game->map))
		return (20);
	if (count_of_directions(game->map) != 1)
		return (21);
	set_direction(game);
	if (zero_is_not_covered(game->map))
		return (22);
	return (0);
}

int	validation_of_file(t_game *game, char *filename, int argc)
{
	int		fd;
	int		error_code;
	int		i;

	i = -1;
	error_code = 0;
	if (argc != 2)
		ft_error(1, game);
	if (extension_is_wrong(filename, ".cub"))
		ft_error(2, game);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_error(3, game);
	game->file = get_full_file(fd);
	close(fd);
	error_code = start_first_part(game, &i, 0);
	if (error_code)
		ft_error(error_code, game);
	error_code = start_second_part(game, &i);
	if (error_code)
		ft_error(error_code, game);
	return (EXIT_SUCCESS);
}
