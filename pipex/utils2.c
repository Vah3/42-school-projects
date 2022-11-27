/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 22:33:04 by vagevorg          #+#    #+#             */
/*   Updated: 2022/06/24 22:33:05 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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
	return (newstr);
}

void	argcchek(int argc)
{
	if (argc < 5)
	{
		ft_printf("Too few arguments");
		exit(1);
	}
}

void	check_and_open(char **argv, int argc, char **env)
{
	int	in;
	int	out;

	argcchek(argc);
	in = open(argv[1], O_RDONLY);
	out = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (access(argv[argc - 1], F_OK) == 0 && access(argv[argc - 1], W_OK) == -1)
	{
		ft_printf("Permission denied, file is %s\n", argv[argc - 1]);
		exit(1);
	}
	if (out < 0)
	{
		ft_printf("Open File %s failed\n", argv[argc - 1]);
		exit(1);
	}
	if (argv[3][0] == '\0')
		exit(1);
	if (in < 0 || argv[2][0] == '\0')
	{
		secondcmd(argv, env, out);
		exit(1);
	}
	dup2(in, 0);
	dup2(out, 1);
}
