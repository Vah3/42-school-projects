/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <edgghaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 15:29:44 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/18 12:49:27 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	splited_size(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

void	free_after_split(char **store)
{
	int	i;

	i = 0;
	while (store && store[i])
	{
		free(store[i]);
		store[i] = NULL;
		i++;
	}
	free(store);
}

int	count_of_tabs(char *content)
{
	int	count;
	int	i;

	i = -1;
	count = 0;
	if (content)
	{
		while (content[++i])
		{
			if (content[i] && content[i] == '\t')
				count++;
		}	
	}
	return (count);
}

int	extension_is_wrong(char *filename, char *extension)
{
	int	i;

	i = 0;
	while (filename[i + 1])
		i++;
	i -= 3;
	if (ft_strcmp(&filename[i], extension))
		return (1);
	return (0);
}
