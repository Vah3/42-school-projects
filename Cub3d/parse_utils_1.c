/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 20:53:11 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/17 16:40:41 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	is_cubes_side(char *name)
{
	return (ft_strcmp(name, "NO") == 0 \
		|| ft_strcmp(name, "SO") == 0 \
		|| ft_strcmp(name, "EA") == 0 \
		|| ft_strcmp(name, "WE") == 0
	);
}

int	is_surface(char *name)
{
	return (ft_strcmp(name, "F") == 0 \
		|| ft_strcmp(name, "C") == 0);
}

int	is_number(char *line)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (i == 0 && (line[i] == '+' || line[i] == '-'))
			continue ;
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != '\t')
			return (0);
	}
	return (1);
}

int	there_is_comma_error(char *line)
{
	int	i;
	int	count;

	i = -1;
	while (line[++i])
	{
		if (line[i] == ',' && line[i + 1] && line[i + 1] == ',')
			return (1);
	}
	i = -1;
	count = 0;
	while (line[++i])
	{
		if (line[i] == ',')
			count++;
	}
	if (count > 2)
		return (1);
	return (0);
}

int	is_empty_line(char *line)
{
	int	i;

	i = -1;
	if (ft_strlen(line) == 0)
		return (1);
	while (line[++i])
	{
		if (line[i] != ' ')
			return (0);
	}
	return (1);
}
