/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initandindex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:43:08 by vagevorg          #+#    #+#             */
/*   Updated: 2022/10/19 18:47:50 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_list	*initlists(char **argv, int *count)
{
	t_list	*a;
	t_list	*head;
	t_list	*first;
	int		bc[2];
	char	**num;

	bc[0] = 0;
	bc[1] = 1;
	while (argv[bc[1]])
	{
		num = ft_split(argv[bc[1]], 32);
		while (num[bc[0]])
		{
			a = (t_list *)malloc(sizeof(t_list));
			a->index = -1;
			a->data = ft_atoi(num[bc[0]]);
			listmaker(&bc[0], &first, &head, &a);
			(*count)++;
		}
		splitfree(num);
		bc[0] = 0;
		bc[1]++;
	}
	a->next = NULL;
	return (first);
}

void	listmaker(int *b, t_list **first, t_list **head, t_list **a)
{
	static int	c;

	c++;
	if (c + *b == 1)
	{
		*head = *a;
		*first = *head;
	}
	else
	{
		(*head)->next = *a;
		*head = *a;
	}
	(*b)++;
}

void	indexseter(t_list **a, int data, int index)
{
	t_list	*tmp;

	tmp = *a;
	while (tmp->data != data)
		tmp = tmp->next;
	tmp->index = index;
}

int	datasetter(t_list **a)
{
	t_list	*data;

	data = *a;
	while (data->next && data->index != -1)
		data = data->next;
	return (data->data);
}

void	indexfunc(t_list **a, int count)
{
	int		data;
	int		index;
	t_list	*cmp;

	index = count;
	while (count > 0)
	{
		cmp = *a;
		data = datasetter(a);
		while (cmp)
		{
			if ((data > cmp->data) && cmp->index == -1)
				data = cmp->data;
			checkrange(a, cmp->data);
			cmp = cmp->next;
		}
		indexseter(a, data, index - count);
		count--;
	}
}
