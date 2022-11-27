/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 18:30:37 by vagevorg          #+#    #+#             */
/*   Updated: 2022/11/26 15:16:37 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*trimfunc(char *b)
{
	long	k;
	char	*a;

	if (ft_strchr(b, '\n') == NULL)
	{
		free (b);
		return (NULL);
	}
	else
	{
		k = ft_strlen(ft_strchr(b, '\n')) - 1;
		a = b;
		b = ft_substr(ft_strchr(b, '\n'), 1, k);
		free (a);
	}
	return (b);
}

size_t	count(char	*la)
{
	size_t	i;

	i = 0;
	while (la && la[i] != '\0')
	{
		if (la[i] == '\n')
			return (i + 1);
		i++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	long int	i;
	char		tmp[BUFFER_SIZE + 1];
	static char	*value;
	char		*baf;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	while (ft_strchr(tmp, '\n') == NULL && i > 0)
	{
		i = read(fd, tmp, BUFFER_SIZE);
		tmp[i] = '\0';
		if (i == -1 || (value == NULL && i == 0))
			return (NULL);
		if (!value)
			value = ft_strdup(tmp);
		else
			value = ft_strjoin(value, tmp);
	}
	i = count(value);
	baf = ft_substr(value, 0, i);
	value = trimfunc(value);
	return (baf);
}
