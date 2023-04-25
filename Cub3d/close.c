/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:17:18 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/18 16:23:36 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_header.h"

char	**g_map;

int	ft_closing(void *player_)
{
	t_player_set	*player;

	player = (t_player_set *) player_;
	mlx_destroy_image(player->d_mlx.mlx, player->img.img1.image);
	mlx_destroy_image(player->d_mlx.mlx, player->img.img2.image);
	mlx_destroy_image(player->d_mlx.mlx, player->img.img3.image);
	mlx_destroy_image(player->d_mlx.mlx, player->img.img4.image);
	mlx_destroy_image(player->d_mlx.mlx, player->gen_img.image);
	mlx_destroy_window(player->d_mlx.mlx, player->d_mlx.win);
	clear_struct(&(player->game));
	exit (0);
	return (0);
}

int	ft_close(int key, void *player)
{
	if (key == 53)
		ft_closing(player);
	return (0);
}
