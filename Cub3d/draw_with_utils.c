/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_with_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:16:01 by vagevorg          #+#    #+#             */
/*   Updated: 2023/04/25 16:22:29 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alg_header.h"

static void	find_step_for_image34(t_player_set *player)
{
	player->img.img3.step = (double)player->img.img3.img_height \
		/ (double)player->draw.lineheight;
	player->img.img3.y = 0;
	if (player->calc.perpwalldist < 1)
		player->img.img3.y = ((double)player->img.img1.img_height \
			- (double)player->img.img3.img_height \
				* player->calc.perpwalldist) / 2;
	player->img.img4.step = (double)player->img.img4.img_height \
		/ (double)player->draw.lineheight;
	player->img.img4.y = 0;
	if (player->calc.perpwalldist < 1)
		player->img.img4.y = ((double)player->img.img1.img_height \
			- (double)player->img.img4.img_height \
				* player->calc.perpwalldist) / 2;
}

static void	find_step_for_image(t_player_set *player)
{
	player->img.img1.step = (double)player->img.img1.img_height \
		/ (double)player->draw.lineheight;
	player->img.img1.y = 0;
	if (player->calc.perpwalldist < 1)
		player->img.img1.y = ((double)player->img.img1.img_height \
			- (double)player->img.img1.img_height \
				* player->calc.perpwalldist) / 2;
	player->img.img2.step = (double)player->img.img2.img_height \
		/ (double)player->draw.lineheight;
	player->img.img2.y = 0;
	if (player->calc.perpwalldist < 1)
		player->img.img2.y = ((double)player->img.img1.img_height \
			- (double)player->img.img2.img_height \
				* player->calc.perpwalldist) / 2;
	find_step_for_image34(player);
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static void	draw_floor_ceil(t_player_set *player, int x, int y)
{
	char	*addr;
	int		surface;

	surface = -1;
	addr = NULL;
	while (++surface < y)
	{
		addr = player->gen_img.addr + (surface * player->gen_img.size_line \
			+ x * player->gen_img.bpp / 8);
		*(int *)addr = create_rgb(player->game.ceil_floor.ceil.red,
				player->game.ceil_floor.ceil.green,
				player->game.ceil_floor.ceil.blue);
	}
	surface = HEIGHT;
	while (--surface >= player->draw.drawend)
	{
		addr = player->gen_img.addr + (surface * player->gen_img.size_line \
			+ x * player->gen_img.bpp / 8);
		*(int *)addr = create_rgb(player->game.ceil_floor.floor.red,
				player->game.ceil_floor.floor.green,
				player->game.ceil_floor.floor.blue);
	}
}

void	drawing_wall(t_player_set *player, int x)
{
	int		y;
	char	*addr;

	y = player->draw.drawstart - 1;
	find_step_for_image(player);
	draw_floor_ceil(player, x, y);
	while (++y < player->draw.drawend)
	{
		addr = player->gen_img.addr + (y * player->gen_img.size_line \
			+ x * player->gen_img.bpp / 8);
		find_side(player, addr);
	}
}
