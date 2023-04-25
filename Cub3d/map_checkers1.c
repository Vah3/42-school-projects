/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:27:17 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/17 16:29:50 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	get_size_of_map(t_game *game, int *i)
{
	int	size;
	int	index;

	size = 0;
	index = *i;
	while (game->file[index]
		|| (game->file[index] && ft_strlen(game->file[index]) == 0))
	{
		size++;
		index++;
	}
	return (size);
}

void	get_map_from_file(t_game *game, int *i, int size_of_map)
{
	int	index;
	int	k;

	game->map = malloc(sizeof(char *) * (size_of_map + 1));
	if (!game->map)
		return ;
	index = *i;
	k = -1;
	while (game->file[index])
	{
		game->map[++k] = ft_strdup(game->file[index]);
		index++;
	}
	game->map[++k] = NULL;
}

int	there_is_empty_line_in_map(char **map, int size)
{
	int	i;

	i = -1;
	while (++i < size)
	{
		if (!map[i] || ft_strlen(map[i]) == 0)
		{
			while (++i < size)
			{
				if (map[i] && (!is_all_spaces(map[i])))
					return (1);
			}
		}
	}
	return (0);
}

int	maps_up_and_down_is_not_correct(char **map, int size)
{
	int	i;

	i = -1;
	while (map[0] && map[0][++i])
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			return (1);
	}
	i = -1;
	while (map[size - 1] && map[size - 1][++i])
	{
		if (map[size - 1][i] != '1' && map[size - 1][i] != ' ')
			return (1);
	}
	return (0);
}

int	there_is_invalid_char(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr("10NEWS \0", map[i][j]))
				return (1);
		}
	}
	return (0);
}
