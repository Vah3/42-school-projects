/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:05:08 by vagevorg          #+#    #+#             */
/*   Updated: 2022/11/27 16:02:18 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child1(int pip[2], char **cmd, char **env)
{
	close(pip[0]);
	dup2(pip[1], 1);
	execve(cmd[0], cmd, env);
	ft_printf("Execution cmd1 is faild");
	exit(1);
}

void	child2(int pip[2], char **cmd2, char **env)
{
	close(pip[1]);
	dup2(pip[0], 0);
	execve(cmd2[0], cmd2, env);
	ft_printf("Execution cmd2 is faild");
	exit(1);
}

void	freefunc(char **cmd, char **cmd2, int fd[2], int id[2])
{
	int	j;

	j = 0;
	close(fd[0]);
	close(fd[1]);
	waitpid(id[0], NULL, 0);
	waitpid(id[1], NULL, 0);
	while (cmd2[j])
		free(cmd2[j++]);
	free(cmd2);
	j = 0;
	while (cmd[j])
		free(cmd[j++]);
	free(cmd);
}

void	spliter(char ***command1, char ***command2, char **argv)
{
	*command1 = ft_split(argv[2], 32);
	*command2 = ft_split(argv[3], 32);
}

void	checker(char **cmd, char **cmd2, char **env)
{
	check_make(&cmd[0], env);
	check_make(&cmd2[0], env);
}
