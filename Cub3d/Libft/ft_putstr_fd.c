/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:40:20 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/17 17:12:58 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd_color(char *s, int fd, char *color)
{
	int	i;

	i = 0;
	ft_putstr_fd(color, fd);
	while (s && s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	ft_putstr_fd(COLOR_RESET, fd);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}
