/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 19:46:49 by vagevorg          #+#    #+#             */
/*   Updated: 2022/05/21 16:49:27 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

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

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*string;
	size_t			lenstr;
	size_t			first;
	unsigned int	index;

	if (!s)
		return (0);
	lenstr = ft_strlen(s);
	first = ft_strlen(s + start);
	if (first < len)
		len = first;
	string = malloc(len + 1);
	index = 0;
	while (index < len && start + index < (unsigned int)lenstr)
	{
		string[index] = s[start + index];
		index++;
	}
	string[index] = '\0';
	return (string);
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
		array[z] = ft_substr(s + start, 0, (len - start));
		start = len;
		z++;
	}
	array[z] = 0;
	return (array);
}
