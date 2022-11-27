/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 22:04:29 by vagevorg          #+#    #+#             */
/*   Updated: 2022/03/19 23:19:38 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len;
	int		ind;

	len = ft_strlen(s1) + ft_strlen(s2);
	ind = 0;
	newstr = malloc(len + 1);
	if (newstr == '\0')
		return (0);
	len = 0;
	while (s1[len])
	{
		newstr[len] = s1[len];
		len++;
	}
	ind = len;
	while (s2[len - ind])
	{
		newstr[len] = s2[len - ind];
		len++;
	}
	newstr[len] = '\0';
	return (newstr);
}
