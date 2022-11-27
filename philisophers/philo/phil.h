/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phil.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:28:05 by vagevorg          #+#    #+#             */
/*   Updated: 2022/08/14 16:43:10 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHIL_H
# define PHIL_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct dataes{
	int				die;
	pthread_mutex_t	*mutex;
	pthread_mutex_t	writing;
}	t_data;

typedef struct parametrs{
	int				philnum;
	int				dietime;
	int				eattime;
	int				sleeptime;
	struct timeval	borntime;
	int				lastmeal;
	int				eatcount;
	int				index;
	t_data			*t_data;
}	t_param;

t_param	**init(char **argv, t_data *data);
int		ft_atoi(const char *str);
int		mytimer(struct timeval borntime);
void	action_print(t_param *phil, char *string, char *color);
void	sleepfun(t_param *phil);
int		check(int argc, char **argv);
void	freefunc(t_param **phil, int n);
int		eatcount(t_param **phil, int *count);
int		initmutex(t_param **phil, t_data *data, int num);

#endif
