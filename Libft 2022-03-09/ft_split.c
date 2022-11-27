/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:46:49 by vagevorg          #+#    #+#             */
/*   Updated: 2022/08/19 15:44:25 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *str, char j)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == j)
			i++;
		if (str[i])
			count++;
		while (str[i] != j && str[i])
			i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	start;
	size_t	len;
	size_t	z;

	array = (char **)malloc ((ft_count(s, c) + 1) * sizeof(char *));
	if (!array || !s)
		return (0);
	z = 0;
	start = 0;
	len = 0;
	while (z < ft_count(s, c))
	{
		while (s[start] == c)
			start++;
		len = start;
		while (s[len] != c && s[len])
			len++;
		array[z] = ft_substr(s, start, (len - start));
		start = len;
		z++;
	}
	array[z] = 0;
	return (array);
}
