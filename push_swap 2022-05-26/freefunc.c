/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freefunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:43:17 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/23 17:54:03 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	freed(t_list **a)
{
	t_list	*prev;

	while (*a)
	{
		prev = *a;
		*a = (*a)->next;
		free(prev);
	}
}

void	splitfree(char **num)
{
	int		i;
	char	*a;

	i = 0;
	while (num[i])
	{
		a = num[i];
		i++;
		free(a);
	}
	free(num[i]);
	free(num);
}
