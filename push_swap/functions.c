/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 15:35:13 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/21 16:50:49 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_swap(t_list	**a, char check)
{
	int		index;
	int		data;
	t_list	*tmp;

	tmp = *a;
	index = tmp->index;
	data = tmp->data;
	tmp->index = tmp->next->index;
	tmp->data = tmp->next->data;
	tmp = tmp->next;
	tmp->data = data;
	tmp->index = index;
	if (check == 'a')
		ft_printf("sa\n");
	else if (check == 'b')
		ft_printf("sb\n");
}

void	ft_shift(t_list **a, char check)
{
	t_list	*tmp;

	tmp = *a;
	if ((*a)->next)
	{
		while ((*a)->next)
			*a = (*a)->next;
		(*a)->next = tmp;
		*a = tmp->next;
		tmp->next = NULL;
	}
	else
		return ;
	if (check == 'a')
		ft_printf("ra\n");
	else if (check == 'b')
		ft_printf("rb\n");
}

void	ft_revshift(t_list **a, char check)
{
	t_list	*head;

	head = *a;
	if ((*a)->next)
	{
		while ((*a)->next->next)
			(*a) = (*a)->next;
		(*a)->next->next = head;
		head = (*a)->next;
		(*a)->next = NULL;
		*a = head;
	}
	else
		return ;
	if (check == 'a')
		ft_printf("rra\n");
	else if (check == 'b')
		ft_printf("rrb\n");
}

void	ft_push(t_list **a, t_list **b, char check)
{
	t_list	*tmp;

	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	if (check == 'b')
		ft_printf("pb\n");
	else if (check == 'a')
		ft_printf("pa\n");
}

ssize_t	ft_atoi(const char *str)
{
	int		index;
	ssize_t	convert;
	int		sign;

	index = 0;
	convert = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -sign;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		convert = convert * 10 + str[index] - '0';
		index++;
	}
	return (sign * convert);
}
