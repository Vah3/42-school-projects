/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:41:06 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/20 20:10:01 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	index;
	size_t	i;

	index = 0;
	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[index] != '\0')
	{
		i = 0;
		while (haystack[index + i] == needle[i])
		{
			if (needle[i + 1] == '\0')
				return ((char *)haystack + index);
			i++;
		}
		index++;
	}
	return (0);
}
