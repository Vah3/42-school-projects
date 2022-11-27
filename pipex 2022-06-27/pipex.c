/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 17:47:43 by vagevorg          #+#    #+#             */
/*   Updated: 2022/11/27 16:02:46 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "Printf/ft_printf.h"

void	check_make(char **cmd, char **env)
{
	char	*command;
	int		i;

	i = 0;
	command = *cmd;
	if (access(command, X_OK) == 0)
		return ;
	command = ft_strjoin("/", *cmd);
	free(*cmd);
	while (env[i] && ft_strstr(env[i], "PATH=") == 0)
		i++;
	env = ft_split(env[i] + 5, ':');
	checkcom(&command, env);
	*cmd = command;
}

void	checkcom(char	**command, char **env)
{
	char	*finaly;
	int		i;
	int		b;

	i = 0;
	b = 0;
	finaly = *command;
	while (env[i] && access(*command, X_OK) != 0)
	{
		*command = ft_strjoin(env[i++], finaly);
		if (access(*command, X_OK) != 0)
			free(*command);
	}
	free(finaly);
	while (env[b])
		free(env[b++]);
	if (env[i] == NULL)
	{
		perror("Comomand not found");
		free(env);
		exit(0);
	}
	free(env);
}

void	secondcmd(char **argv, char **env, int fd)
{
	char	**command;
	int		pid;

	if (argv[2][0] != '\0')
		ft_printf("File %s does not exist or is not readable\n", argv[1]);
	else
		ft_printf("Cmd1 not found\n");
	dup2(fd, 1);
	pid = fork();
	if (pid == 0)
	{
		command = ft_split(argv[3], 32);
		check_make(&command[0], env);
		execve(command[0], command, env);
		ft_printf("Execution is faild\n");
		exit(1);
	}
}

int	main(int argc, char **argv, char **env)
{
	char	**cmd;
	char	**cmd2;
	int		pip[2];
	int		forkid[2];

	check_and_open(argv, argc, env);
	if (pipe(pip) == -1)
		exit(1);
	spliter(&cmd, &cmd2, argv);
	checker(&cmd[0], &cmd2[0], env);
	forkid[0] = fork();
	if (forkid[0] == 0)
		child1(pip, cmd, env);
	else
	{	
		forkid[1] = fork();
		if (forkid[1] == 0)
			child2(pip, cmd2, env);
	}
	freefunc(cmd, cmd2, pip, forkid);
	return (0);
}
