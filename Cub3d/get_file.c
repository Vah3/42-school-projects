/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgghaza <edgghaza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:52:55 by edgghaza          #+#    #+#             */
/*   Updated: 2023/01/18 13:19:08 by edgghaza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

char	*tab_to_4space(char *content)
{
	int		i;
	char	*new;
	int		k;

	new = malloc(sizeof(char) * ft_strlen(content) + 3
			* count_of_tabs(content) + 1);
	if (!new)
		return (NULL);
	i = -1;
	k = -1;
	while (content[++i])
	{
		if (content[i] == '\t')
		{
			new[++k] = ' ';
			new[++k] = ' ';
			new[++k] = ' ';
			new[++k] = ' ';
		}
		else
			new[++k] = content[i];
	}
	new[++k] = '\0';
	free(content);
	return (new);
}

char	*final_line(char *content)
{
	int		i;
	char	*new;

	if (!content)
		return (NULL);
	new = malloc(sizeof(char) * (ft_strlen(content) + 1));
	if (!new)
		return (NULL);
	i = -1;
	while (content[++i])
	{
		if (content[i] && content[i] == '\n' )
		{
			new[i] = '\0';
			free(content);
			return (new);
		}
		else if (content[i])
			new[i] = content[i];
	}
	new[i] = '\0';
	free(content);
	return (new);
}

void	clear_list(t_list **list_map)
{
	t_list	*temp;

	while (*list_map)
	{
		temp = (*list_map)->next;
		free((*list_map)->content);
		(*list_map)->content = NULL;
		free(*list_map);
		(*list_map) = temp;
	}
	*list_map = NULL;
}

char	**list_to_array(t_list	*list_map)
{
	t_list	*temp;
	char	**final_array;
	int		i;

	final_array = malloc(sizeof(*final_array) * (ft_lstsize(list_map) + 1));
	if (!final_array)
		return (NULL);
	temp = list_map;
	i = -1;
	while (temp)
	{
		final_array[++i] = ft_strdup(temp->content);
		final_array[i] = final_line(final_array[i]);
		final_array[i] = tab_to_4space(final_array[i]);
		temp = temp->next;
	}
	final_array[++i] = NULL;
	clear_list(&list_map);
	return (final_array);
}

char	**get_full_file(int fd)
{
	t_list	*full_file;
	char	*s;

	full_file = NULL;
	s = NULL;
	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		ft_lstadd_back(&full_file, ft_lstnew(s));
	}
	return (list_to_array(full_file));
}
