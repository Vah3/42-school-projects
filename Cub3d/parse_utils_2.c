/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:41:16 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/17 16:41:37 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_direction(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (ft_strchr(DIR_CHAR, game->map[i][j]))
			{
				game->player.face_to = game->map[i][j];
				game->player.x = j + 0.5;
				game->player.y = i + 0.5;
				game->map[i][j] = '0';
				return ;
			}
		}
	}
}

void	skip_spaces_and_get_sizeof_map(t_game *game, int *i)
{
	while (game->file[*i] \
		&& (is_all_spaces(game->file[*i]) || ft_strlen(game->file[*i]) == 0))
		(*i) += 1;
	game->size_of_map = get_size_of_map(game, i);
}
