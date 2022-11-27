/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 19:26:05 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/10 14:32:19 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *s)
{	
	int		i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	long int	index;

	index = 0;
	while (s && s[index])
	{
		if (s[index] == (char )c)
			return ((char *)s + index);
		index++;
	}
	if (c != '\0')
		return (0);
	return ((char *)s + index);
}

char	*ft_strdup(char *s)
{
	char	*v;
	long	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	v = (char *) malloc(i + 1);
	if (v == 0)
		return (0);
	i = 0;
	while (s && s[i] != '\0')
	{
		v[i] = s[i];
		i++;
	}
	v[i] = '\0';
	return (v);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char				*string;
	size_t				lenstr;
	size_t				first;
	unsigned long int	index;

	if (!s || !*s)
		return (0);
	lenstr = ft_strlen(s);
	first = ft_strlen(s + start);
	if (first < len)
		len = first;
	string = malloc(len + 1);
	index = 0;
	while (index < len && start + index < (unsigned long int)lenstr)
	{
		string[index] = s[start + index];
		index++;
	}
	string[index] = '\0';
	return (string);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char		*newstr;
	long int	len;
	long int	ind;

	len = ft_strlen(s1) + ft_strlen(s2);
	ind = 0;
	newstr = malloc(len + 1);
	if (!newstr)
		return (0);
	len = 0;
	while (s1 && s1[len] != '\0')
	{
		newstr[len] = s1[len];
		len++;
	}
	ind = len;
	while (s2 && s2[len - ind] != '\0')
	{
		newstr[len] = s2[len - ind];
		len++;
	}
	newstr[len] = '\0';
	free(s1);
	return (newstr);
}
