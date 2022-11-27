/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 21:20:15 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/21 21:24:16 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	steps_a(t_list **a, int range, long *count, long *revcount)
{
	t_list	*cmp;
	t_list	*tmp;

	cmp = *a;
	while (cmp->index > range && ++(*count))
		cmp = cmp->next;
	cmp = *a;
	while (cmp)
	{
		if (cmp->index <= range)
			tmp = cmp;
		cmp = cmp->next;
	}
	while (tmp && ++(*revcount))
		tmp = tmp->next;
}

void	steps_b(long index, t_list **b, long *step_b, long *revstep_b)
{
	t_list	*tmp;
	t_list	*cmp;
	int		dif;

	dif = 1000000;
	tmp = *b;
	cmp = *b;
	while (tmp)
	{
		if (((index - tmp->index) < dif) && ((index - tmp->index) > 0))
		{
			dif = index - tmp->index;
			cmp = tmp;
		}
			tmp = tmp->next;
	}
	if ((*b) && cmp && dif == 1000000)
	{
		while (cmp->data != mindata(b))
			cmp = cmp->next;
		cmp = cmp->next;
	}
	if (*b)
		checkloc1(b, cmp, step_b, revstep_b);
}

void	checkloc1(t_list **a, t_list *cmp, long *step_b, long *revstep_b)
{
	long	i;
	t_list	*tmp;
	long	count;

	count = 0;
	tmp = *a;
	i = 0;
	while (tmp && tmp != cmp)
	{
		i++;
		tmp = tmp->next;
	}
	tmp = *a;
	while (tmp && ++count)
		tmp = tmp->next;
	if (i > 0 && i > count / 2)
		*revstep_b = count - i;
	else if (i <= count / 2)
		*step_b = i;
}

void	rotate_b(long *step_b, long *revstep_b, t_list **b)
{
	while (*step_b > 0)
	{
		ft_shift(b, 'b');
		(*step_b)--;
	}
	while (*revstep_b >= 1)
	{
		ft_revshift(b, 'b');
		(*revstep_b)--;
	}
}

void	rotate_a(long *step_a, long *revstep_a, t_list **a)
{
	while ((*step_a <= *revstep_a) && *step_a > 0)
	{
		ft_shift(a, 'a');
		(*step_a)--;
	}
	while ((*step_a > *revstep_a) && *revstep_a > 0)
	{
		ft_revshift(a, 'a');
		(*revstep_a)--;
	}
}
