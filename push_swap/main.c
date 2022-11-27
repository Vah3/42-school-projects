/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:25:00 by vagevorg          #+#    #+#             */
/*   Updated: 2022/10/19 18:28:31 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		count;

	checkdigit(argv);
	count = 0;
	if (argc > 1)
	{
		a = initlists(argv, &count);
		checkdublicate(&a);
		indexfunc(&a, count);
		if (count == 2)
			twosort(&a);
		else if (count == 3 && sortcheck(&a, count) == 0)
			threesort(&a);
		else if (count == 100 && sortcheck(&a, count) == 0)
			houndred(&a, &b);
		else if (count == 500 && sortcheck(&a, count) == 0)
			fivehoundred(&a, &b);
		else if (sortcheck(&a, count) == 0)
			sortfunc(&a, &b, count);
		freed(&a);
	}
	return (0);
}
