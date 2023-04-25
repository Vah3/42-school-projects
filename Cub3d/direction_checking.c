/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_checking.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:24:26 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/17 16:22:22 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_empty_keys_value(t_game *game, char *key_name)
{
	if (ft_strcmp(key_name, "NO") == 0)
	{
		if (!(game->directions.north.path_to_xpm))
			return (1);
	}
	else if (ft_strcmp(key_name, "SO") == 0)
	{
		if (!(game->directions.south.path_to_xpm))
			return (1);
	}
	else if (ft_strcmp(key_name, "WE") == 0)
	{
		if (!(game->directions.west.path_to_xpm))
			return (1);
	}
	else if (ft_strcmp(key_name, "EA") == 0)
	{
		if (!(game->directions.east.path_to_xpm))
			return (1);
	}
	return (0);
}

int	is_valid_path(t_game *game, char *path_to_xpm)
{
	int	fd;

	(void) game;
	if (extension_is_wrong(path_to_xpm, ".xpm"))
		return (0);
	fd = open(path_to_xpm, O_RDONLY);
	if (fd < 0)
		return (0);
	close(fd);
	return (1);
}

void	assign_direction(t_game *game, char **splited_info, \
	int *count_of_information)
{
	if (ft_strcmp(splited_info[0], "NO") == 0)
		game->directions.north.path_to_xpm = ft_strdup(splited_info[1]);
	else if (ft_strcmp(splited_info[0], "SO") == 0)
		game->directions.south.path_to_xpm = ft_strdup(splited_info[1]);
	else if (ft_strcmp(splited_info[0], "WE") == 0)
		game->directions.west.path_to_xpm = ft_strdup(splited_info[1]);
	else if (ft_strcmp(splited_info[0], "EA") == 0)
		game->directions.east.path_to_xpm = ft_strdup(splited_info[1]);
	(*count_of_information)++;
}

int	is_all_spaces(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] != ' ')
			return (0);
	}
	return (1);
}
