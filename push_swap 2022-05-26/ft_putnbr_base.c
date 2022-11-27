/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:45:12 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/05 21:11:56 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_putnbr1(ssize_t nbra, char *base, int *count)
{
	int			i;
	int			countbase;
	int			a[1000];

	countbase = 0;
	i = 0;
	if (nbra < 0)
	{
		ft_putchar('-', count);
		nbra = -nbra;
	}
	while (base[countbase] != '\0')
		countbase++;
	while (nbra > 0)
	{
		a[i] = nbra % countbase;
		nbra = nbra / countbase;
		i++;
	}
	while (--i != -1)
		ft_putchar(base[a[i]], count);
}

void	ft_putnbr2(size_t nbra, char *base, int *count)
{
	int			i;
	int			countbase;
	int			a[1000];

	countbase = 0;
	i = 0;
	while (base[countbase] != '\0')
		countbase++;
	while (nbra > 0)
	{
		a[i] = nbra % countbase;
		nbra = nbra / countbase;
		i++;
	}
	while (--i != -1)
		ft_putchar(base[a[i]], count);
}

void	ft_putnbr_base(ssize_t num, char *bas, char c, int *count)
{
	unsigned int	k;

	if (c == 'p')
	{
		ft_putchar('0', count);
		ft_putchar('x', count);
		if (num == 0)
		{
			ft_putchar('0', count);
			return ;
		}
		ft_putnbr2(num, bas, count);
	}
	if (num == 0)
	{
		ft_putchar('0', count);
		return ;
	}
	if (c == 'x' || c == 'X' || c == 'u')
	{
		k = (unsigned int)num;
		ft_putnbr1(k, bas, count);
	}
	else if (c == 'i' || c == 'd')
		ft_putnbr1(num, bas, count);
}
