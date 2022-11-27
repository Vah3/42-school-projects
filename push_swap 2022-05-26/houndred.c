/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   houndred.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:30:48 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/21 21:47:32 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	pushback_b(t_list **a, t_list **b)
{
	t_list	*tmp;
	long	count;

	tmp = *b;
	count = 0;
	while (tmp->data != mindata(b) && ++count)
		tmp = tmp->next;
	if (count >= 50)
	{
		while (count < 99 && ++count)
			ft_revshift(b, 'b');
	}
	else if (count < 50)
	{
		while (count >= 0 && count--)
			ft_shift(b, 'b');
	}
	while (*b)
		ft_push(b, a, 'a');
}

void	houndred(t_list **a, t_list **b)
{
	int		i;
	int		j;
	int		range;
	t_list	*head;

	head = *a;
	range = 19;
	i = 0;
	j = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 20)
		{
			steps(a, b, range);
			j++;
		}
		i++;
		range = range + 20;
	}
	pushback_b(a, b);
}

void	findindex(t_list **a, long step_a, long revstep_a, long *index)
{
	t_list	*tmp;
	long	count;

	count = 0;
	*index = 0;
	tmp = *a;
	while (tmp && ++count)
		tmp = tmp->next;
	tmp = *a;
	if (step_a <= revstep_a)
	{
		while (step_a > 0 && step_a--)
			tmp = tmp->next;
	}
	else if (step_a > revstep_a)
	{
		revstep_a = count - revstep_a;
		while (revstep_a > 0 && revstep_a--)
			tmp = tmp->next;
	}
	*index = tmp->index;
}

void	steps(t_list	**a, t_list	**b, int range)
{
	long	step_a;
	long	revstep_a;
	long	step_b;
	long	revstep_b;
	long	index;

	step_a = 0;
	revstep_a = 0;
	step_b = 0;
	revstep_b = 0;
	steps_a(a, range, &step_a, &revstep_a);
	findindex(a, step_a, revstep_a, &index);
	steps_b(index, b, &step_b, &revstep_b);
	if (step_a <= revstep_a)
		pusherab(&step_a, &step_b, a, b);
	else if (step_a > revstep_a)
		revpusherab(&revstep_a, &revstep_b, a, b);
	rotate_a(&step_a, &revstep_a, a);
	rotate_b(&step_b, &revstep_b, b);
	ft_push(a, b, 'b');
}

void	pusherab(long *step_a, long *step_b, t_list **a, t_list **b)
{
	while (*step_a > 0 && *step_b > 0)
	{
		ft_shift(a, 'r');
		ft_shift(b, 'r');
		ft_printf("rr\n");
		(*step_a)--;
		(*step_b)--;
	}
}
