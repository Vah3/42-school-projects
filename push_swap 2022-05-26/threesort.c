/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 21:40:33 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/22 15:46:05 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	threesortmain(t_list **a, t_list **tmp1, t_list **tmp2, t_list **tmp3)
{
	if ((*tmp1)->data < (*tmp2)->data && (*tmp1)->data < (*tmp3)->data)
	{
		ft_shift(a, 'a');
		if ((*tmp2)->data > (*tmp3)->data)
			ft_swap(a, 'a');
		ft_revshift(a, 'a');
	}
	else if ((*tmp2)->data < (*tmp1)->data && (*tmp2)->data < (*tmp3)->data)
	{
		if ((*tmp1)->data < (*tmp3)->data)
			ft_swap(a, 'a');
		else
			ft_shift(a, 'a');
	}
	else if ((*tmp3)->data < (*tmp1)->data && (*tmp3)->data < (*tmp2)->data)
	{
		if ((*tmp1)->data > (*tmp2)->data)
			ft_swap(a, 'a');
		ft_revshift(a, 'a');
	}
}

void	threesort(t_list **a)
{
	t_list	*tmp1;
	t_list	*tmp2;
	t_list	*tmp3;

	tmp1 = *a;
	tmp2 = (*a)->next;
	tmp3 = tmp2->next;
	threesortmain(a, &tmp1, &tmp2, &tmp3);
}

int	sortcheck(t_list **a, int count)
{
	t_list	*tmp;

	tmp = *a;
	while (count > 1)
	{
		if (tmp->data < tmp->next->data)
		{
			tmp = tmp->next;
			count--;
		}
		else
			return (0);
	}
	return (1);
}

void	revpusherab(long *revstep_a, long *revstep_b, t_list **a, t_list **b)
{
	while (*revstep_a > 0 && *revstep_b >= 1)
	{
		ft_revshift(a, 'r');
		ft_revshift(b, 'r');
		ft_printf("rrr\n");
		(*revstep_a)--;
		(*revstep_b)--;
	}
}

void	twosort(t_list **a)
{
	t_list	*tmp;

	tmp = (*a)->next;
	if ((*a)->data > tmp->data)
		ft_swap(a, 'a');
}
