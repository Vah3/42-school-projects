/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <vagevorg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 20:06:23 by vagevorg          #+#    #+#             */
/*   Updated: 2022/11/27 16:02:36 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "ft_printf.h"
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

void	child1(int pip[2], char **cmd, char **env);
void	child2(int pip[2], char **cmd2, char **env);
void	freefunc(char **cmd, char **cmd2, int fd[2], int id[2]);
void	spliter(char ***command1, char ***command2, char **argv);
void	checker(char **cmd, char **cmd2, char **env);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
char	**ft_split(char *s, char c);
char	*ft_strstr(const char *haystack, const char *needle);
void	openfiles(char **argv, int fd[2]);
void	check_make(char **cmd, char **env);
void	checkcom(char **command, char **env);
int		ft_printf(const char *s, ...);
void	check_and_open(char **argv, int argc, char **env);
void	secondcmd(char **argv, char **env, int fd);

#endif
