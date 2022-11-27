/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 21:15:15 by vagevorg          #+#    #+#             */
/*   Updated: 2022/04/11 00:24:23 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

void	ft_putchar(char c, int *count)
{
	write(1, &c, 1);
	*count = *count + 1;
}

void	ft_putstr(char *s, int *count)
{
	int	i;

	i = 0;
	if (!s)
	{
		ft_putstr("(null)", count);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i], count);
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char )c)
			return ((char *)s + index);
		index++;
	}
	if (c != '\0')
		return (0);
	return ((char *)s + index);
}

void	printablef(const char *s, va_list variables, int *i, int *count)
{
	if (s[*i + 1] == 'c')
		ft_putchar(va_arg(variables, int), count);
	else if (s[*i + 1] == 's')
		ft_putstr(va_arg(variables, char *), count);
	else if (s[*i + 1] == 'd' || s[*i + 1] == 'i')
		ft_putnbr_base(va_arg(variables, int), "0123456789", 'i', count);
	else if (s[*i + 1] == 'u')
		ft_putnbr_base(va_arg(variables, int), "0123456789", 'u', count);
	else if (s[*i + 1] == 'x')
		ft_putnbr_base(va_arg(variables, int), "0123456789abcdef", 'x', count);
	else if (s[*i + 1] == 'X')
		ft_putnbr_base(va_arg(variables, int), "0123456789ABCDEF", 'X', count);
	else if (s[*i + 1] == 'p')
		ft_putnbr_base(va_arg(variables, size_t),
			"0123456789abcdef", 'p', count);
	else if (s[*i + 1] == '%')
		ft_putchar('%', count);
	*i += 1;
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		count;
	va_list	variables;

	va_start(variables, s);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '%' && ft_strchr("csduixXp%", s[i + 1]))
			printablef(s, variables, &i, &count);
		else
			ft_putchar(s[i], &count);
		i++;
	}
	va_end(variables);
	return (count);
}
