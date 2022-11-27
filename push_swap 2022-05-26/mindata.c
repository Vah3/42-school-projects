/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mindata.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 14:22:02 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/21 21:31:46 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	mindata(t_list **b)
{
	int		data;
	t_list	*cmp;

	cmp = *b;
	if (cmp)
		data = cmp->data;
	else
		return (0);
	while (cmp)
	{
		if (data > cmp->data)
			data = cmp->data;
		if (cmp->next)
			cmp = cmp->next;
		else
			break ;
	}
	return (data);
}
