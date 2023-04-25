/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 18:05:23 by vagevorg          #+#    #+#             */
/*   Updated: 2023/01/10 16:02:37 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	while ((*lst))
	{
		buf = (*lst)->next;
		del ((*lst)->content);
		free (*lst);
		*lst = buf;
	}
	*lst = NULL;
}
