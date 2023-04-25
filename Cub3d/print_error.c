/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 18:51:13 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/18 17:08:43 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	ft_error3(int error_code)
{
	if (error_code == 19)
		ft_putstr_fd_color("Left wall is invalid\n", 2, RED);
	else if (error_code == 20)
		ft_putstr_fd_color("Right wall is invalid\n", 2, RED);
	else if (error_code == 21)
		ft_putstr_fd_color("Invalid directions count in map\n", 2, RED);
	else if (error_code == 22)
		ft_putstr_fd_color("0 or player direction \
is covered by space\n", 2, RED);
	else if (error_code == 23)
		ft_putstr_fd_color("invalid charachter in map\n", 2, RED);
}

void	ft_error2(int error_code)
{
	if (error_code == 9)
		ft_putstr_fd_color("You should pass 3 color codes\n", 2, RED);
	else if (error_code == 10)
		ft_putstr_fd_color("Color code should be number\n", 2, RED);
	else if (error_code == 11)
		ft_putstr_fd_color("Color code should be [0, 255]\n", 2, RED);
	if (error_code == 12)
		ft_putstr_fd_color("Double assigning floor\n", 2, RED);
	else if (error_code == 13)
		ft_putstr_fd_color("Double assigning ceil\n", 2, RED);
	else if (error_code == 14)
		ft_putstr_fd_color("Less information\n", 2, RED);
	else if (error_code == 15)
		ft_putstr_fd_color("Empty map\n", 2, RED);
	else if (error_code == 16)
		ft_putstr_fd_color("Empty map\n", 2, RED);
	else if (error_code == 17)
		ft_putstr_fd_color("Empty line in map\n", 2, RED);
	else if (error_code == 18)
		ft_putstr_fd_color("Up and down error in map\n", 2, RED);
	else
		ft_error3(error_code);
}

void	ft_error(int error_code, t_game *game)
{
	if (error_code == 1)
		ft_putstr_fd_color("Wrong count of arguments!\n", 2, RED);
	else if (error_code == 2)
		ft_putstr_fd_color("Wrong extension!\n", 2, RED);
	else if (error_code == 3)
		ft_putstr_fd_color("Can't open file!\n", 2, RED);
	else if (error_code == 4)
		ft_putstr_fd_color("Bad arguments count in files row\n", 2, RED);
	else if (error_code == 5)
		ft_putstr_fd_color("Invalid key\n", 2, RED);
	else if (error_code == 6)
		ft_putstr_fd_color("Double assigning key\n", 2, RED);
	else if (error_code == 7)
		ft_putstr_fd_color("Invalid path to texture\n", 2, RED);
	else if (error_code == 8)
		ft_putstr_fd_color("There comma error in colors argument\n", 2, RED);
	else
		ft_error2(error_code);
	if (error_code > 3)
		clear_struct(game);
	exit(EXIT_FAILURE);
}
