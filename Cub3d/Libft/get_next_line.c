/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:42:44 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/17 16:43:01 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_for_read(char *s, char c)
{
	int		i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof (*res) * (ft_strlen(s) + 2));
	if (!res)
		return (NULL);
	while (i < ft_strlen(s))
	{
		res[i] = s[i];
		i++;
	}
	free(s);
	res[i] = c;
	res[i + 1] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	char	*s;
	char	c;
	int		rd;

	s = NULL;
	rd = 0;
	c = '\0';
	while (c != '\n')
	{
		rd = read(fd, &c, 1);
		if (rd == -1)
		{
			free(s);
			return (NULL);
		}
		if (rd == 0 || c == '\0')
			return (s);
		s = ft_strjoin_for_read(s, c);
	}
	return (s);
}
