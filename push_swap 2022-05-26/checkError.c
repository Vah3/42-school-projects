/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkError.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 18:23:14 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/26 15:58:30 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	print_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	checkdigit(char	**argv)
{
	int	i;
	int	i2;

	i = 1;
	i2 = 0;
	while (argv[i])
	{
		if (argv[i][i2] == 0)
			print_error();
		while (argv[i][i2])
		{
			if (argv[i][i2] == '-')
			{
				if (argv[i][i2 - 1] && argv[i][i2 - 1] != 32)
					print_error();
				i2++;
			}
			if (argv[i][i2] && argv[i][i2] != 32 &&
					!(argv[i][i2] >= '0' && argv[i][i2] <= '9'))
				print_error();
			i2++;
		}
		i2 = 0;
		i++;
	}
}

void	checkrange(t_list **a, ssize_t num)
{
	if (num < -2147483648 || num > 2147483647)
	{
		freed(a);
		print_error();
	}
}

void	checkdublicate(t_list	**a)
{
	t_list	*first;
	t_list	*current;

	first = *a;
	while (first)
	{
		current = first->next;
		while (current)
		{
			if (first->data == current->data)
			{
				freed(a);
				print_error();
			}
			current = current->next;
		}
		first = first->next;
	}
}
