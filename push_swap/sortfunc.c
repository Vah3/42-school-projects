/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:57:12 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/21 21:51:03 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushback(t_list	**a, t_list	**b, int count)
{
	while (count > 0)
	{
		ft_push(b, a, 'a');
		count--;
	}
}

int	checking(t_list **a, t_list **b, int count, int i)
{
	if (sortcheck(a, count - i))
	{
		pushback(a, b, i);
		return (1);
	}
	return (0);
}

void	checkloc(t_list	**a, int count, int index, char *c)
{
	int		i;
	t_list	*tmp;

	tmp = *a;
	i = 1;
	while (tmp->index != index)
	{
		i++;
		tmp = tmp->next;
	}
	if (count - i < count / 2)
		*c = 'r';
	else
		*c = 'n';
}

void	sortfunc(t_list **a, t_list **b, int count)
{
	int		i;
	char	c;

	i = 0;
	while (i < count - 3)
	{
		if (checking(a, b, count, i) == 1)
			return ;
		checkloc(a, count, i, &c);
		while ((*a)->index != i)
		{
			if (c == 'n')
				ft_shift(a, 'a');
			else if (c == 'r')
				ft_revshift(a, 'a');
			if (checking(a, b, count, i) == 1)
				return ;
		}
		ft_push(a, b, 'b');
		i++;
	}
	threesort(a);
	pushback(a, b, count - 3);
}
