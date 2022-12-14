/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_correct_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 22:10:42 by edgghaza          #+#    #+#             */
/*   Updated: 2022/10/11 18:39:23 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	assigning1(char	**trash, char **cmd, int *i, int *j)
{
	if ((*trash)[*i] == '\\' && (*trash)[(*i) + 1]
		&& ((*trash)[(*i) + 1] == '\'' || (*trash)[(*i) + 1] == '\"'))
		(*cmd)[(*j)++] = (*trash)[++(*i)];
	else
		(*cmd)[(*j)++] = (*trash)[(*i)];
}

static void	assigning(char	**trash, char **cmd, int *i, int *j)
{
	if ((*trash)[*i] == '\\' && (*trash)[(*i) + 1]
		&& (*trash)[(*i) + 1] == '\"')
		(*cmd)[(*j)++] = (*trash)[++(*i)];
	else
		(*cmd)[(*j)++] = (*trash)[(*i)];
}

static int	correct_len(char *trash)
{
	int	i;
	int	count_of_symbols;

	i = 0;
	count_of_symbols = 0;
	while (trash && trash[i])
	{
		skip_slesh_quote_1(trash, &i, &count_of_symbols);
		if (trash[i] == '"')
		{
			while (trash[++i] && trash[i] != '"')
				skip_slesh_quote_2(trash, &i, &count_of_symbols);
		}
		if (trash[i] == '\'')
		{
			while (trash[++i] && trash[i] != '\'')
				count_of_symbols++;
		}
		if (!trash[i])
			break ;
		count_of_symbols += (trash[i] != '"' && trash[i] != '\'');
		i++;
	}
	return (count_of_symbols);
}

static char	*clear_cmd(char *trash, int count_of_symbols)
{
	char	*cmd;
	int		i;
	int		j;

	i = 0;
	j = 0;
	cmd = (char *)malloc(sizeof(char) * (count_of_symbols + 1));
	if (!cmd)
		return (NULL);
	while (trash && trash[i])
	{
		if (trash[i] == '"')
			while (trash[++i] && trash[i] != '"')
				assigning(&trash, &cmd, &i, &j);
		if (trash[i] == '\'')
			while (trash[++i] && trash[i] != '\'')
				cmd[j++] = trash[i];
		if (!trash[i])
			break ;
		if (trash[i] != '"' && trash[i] != '\'')
			assigning1(&trash, &cmd, &i, &j);
		i++;
	}
	cmd[j] = '\0';
	return (cmd);
}

char	*get_correct_cmd(char *trash)
{
	int		count_of_symbols;
	char	*cmd;

	if (!trash)
		return (0);
	count_of_symbols = correct_len(trash);
	cmd = clear_cmd(trash, count_of_symbols);
	free(trash);
	return (cmd);
}
