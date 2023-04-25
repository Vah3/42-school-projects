/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <edgghaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:16:27 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/18 12:46:38 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	norm(char **splited_colors, int *error_code)
{
	int	i;
	int	color_code;

	i = -1;
	while (splited_colors[++i])
	{
		if (!is_number(splited_colors[i]))
		{
			*error_code = 10;
			free_after_split(splited_colors);
			return (0);
		}
		color_code = ft_atoi(splited_colors[i]);
		if (color_code < 0 || color_code > 255)
		{
			*error_code = 11;
			free_after_split(splited_colors);
			return (0);
		}
	}
	return (1);
}

int	is_valid_color_codes(char *color_codes_line, int *error_code)
{
	char	**splited_colors;

	if (there_is_comma_error(color_codes_line))
	{
		*error_code = 8;
		return (0);
	}
	splited_colors = ft_split(color_codes_line, ',');
	if (splited_size(splited_colors) != 3)
	{
		*error_code = 9;
		free_after_split(splited_colors);
		return (0);
	}
	else
	{
		if (!norm(splited_colors, error_code))
		{
			return (0);
		}
	}
	free_after_split(splited_colors);
	return (1);
}

int	can_assign(t_game *game, char *key, int *err_code)
{
	if (ft_strcmp(key, "F") == 0)
	{
		if (game->ceil_floor.floor.red == -1 \
			&& game->ceil_floor.floor.green == -1 \
			&& game->ceil_floor.floor.blue == -1)
		{
			return (1);
		}
		*err_code = 12;
	}
	else
	{
		if (game->ceil_floor.ceil.red == -1 \
			&& game->ceil_floor.ceil.green == -1 \
			&& game->ceil_floor.ceil.blue == -1)
		{
			return (1);
		}
		*err_code = 13;
	}
	return (0);
}

void	assign_rgb(t_game *game, char **info, int *count_of_information)
{
	char	**color_codes;

	color_codes = ft_split(info[1], ',');
	if (ft_strcmp(info[0], "F") == 0)
	{
		game->ceil_floor.floor.red = ft_atoi(color_codes[0]);
		game->ceil_floor.floor.green = ft_atoi(color_codes[1]);
		game->ceil_floor.floor.blue = ft_atoi(color_codes[2]);
	}
	else
	{
		game->ceil_floor.ceil.red = ft_atoi(color_codes[0]);
		game->ceil_floor.ceil.green = ft_atoi(color_codes[1]);
		game->ceil_floor.ceil.blue = ft_atoi(color_codes[2]);
	}
	(*count_of_information)++;
	free_after_split(color_codes);
}
