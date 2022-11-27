/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 22:19:43 by vagevorg          #+#    #+#             */
/*   Updated: 2022/04/11 00:04:29 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

void	ft_putnbr_base(ssize_t num, char *bas, char c, int *count);
void	ft_putchar(char c, int *count);
int		ft_printf(const char *s, ...);
void	ft_putstr(char	*s, int *count);

#endif
