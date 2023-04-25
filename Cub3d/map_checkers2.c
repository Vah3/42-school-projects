/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checkers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:31:26 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/17 16:37:04 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	left_wall_is_not_correct(char **map)
{
	int	i;
	int	j;
	int	s;

	s = -1;
	while (map[++s])
		;
	s--;
	i = -1;
	while (++i < s)
	{
		j = 0;
		while (map[i][j] && map[i][j] == ' ')
			j++;
		if (map[i][j] != '1')
			return (1);
	}
	return (0);
}

int	right_wall_is_not_correct(char **map)
{
	int	i;
	int	j;
	int	s;

	s = -1;
	while (map[++s])
		;
	s--;
	i = -1;
	while (++i < s)
	{
		j = ft_strlen(map[i]) - 1;
		while (map[i][j] && map[i][j] == ' ')
			j--;
		if (map[i][j] != '1')
			return (1);
	}
	return (0);
}

int	is_covered_by_space(char **map, int i, int j)
{
	return (
		((j >= ft_strlen(map[i - 1])) || (map[i - 1] \
			&& map[i - 1][j] && map[i - 1][j] == ' ')) || \
		((j >= ft_strlen(map[i + 1])) || (map[i + 1] \
			&& map[i + 1][j] && map[i + 1][j] == ' ')) || \
		(map[i] && map[i][j - 1] && map[i][j - 1] == ' ') || \
		(map[i] && map[i][j + 1] && map[i][j + 1] == ' ')
		);
}

int	zero_is_not_covered(char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == '0' && is_covered_by_space(map, i, j))
				return (1);
		}
	}
	return (0);
}

int	count_of_directions(char **map)
{
	int	i;
	int	j;
	int	count;
	int	s;

	s = -1;
	while (map[++s])
		;
	i = -1;
	count = 0;
	while (++i < s)
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr(DIR_CHAR, map[i][j]))
				count++;
		}
	}
	return (count);
}
