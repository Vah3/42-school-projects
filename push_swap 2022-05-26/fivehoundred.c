/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   houndred.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:30:48 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/21 20:47:16 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushback_five(t_list **a, t_list **b)
{
	t_list	*tmp;
	long	count;

	tmp = *b;
	count = 0;
	while (tmp->data != mindata(b))
	{
		tmp = tmp->next;
		count++;
	}
	if (count >= 250)
	{
		while (count < 499 && ++count)
			ft_revshift(b, 'b');
	}
	else if (count < 250)
	{
		while (count >= 0 && count--)
			ft_shift(b, 'b');
	}
	while (*b)
		ft_push(b, a, 'a');
}

void	fivehoundred(t_list **a, t_list **b)
{
	int		i;
	int		j;
	int		range;
	t_list	*head;

	head = *a;
	range = 49;
	i = 0;
	j = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 50)
		{
			steps(a, b, range);
			j++;
		}
		i++;
		range = range + 50;
	}
	pushback_five(a, b);
}
