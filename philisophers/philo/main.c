/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:24:18 by vagevorg          #+#    #+#             */
/*   Updated: 2022/08/10 16:57:39 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

void	eat(t_param *phil, int index, struct timeval borntime)
{
	int	k;

	if (index == phil->philnum)
		k = -1 * index + 1;
	else
		k = 1;
	pthread_mutex_lock (&phil->t_data->mutex[index - 1]);
	if (phil->t_data->die)
		printf("\033[1;33m%d %d Philisopher has taken the fork\n",
			mytimer(borntime), index);
	pthread_mutex_lock(&phil->t_data->mutex[index - 1 + k]);
	if (phil->t_data->die)
		printf("\033[1;33m%d %d Philisopher has taken the second fork\n",
			mytimer(borntime), index);
	phil->lastmeal = mytimer(borntime);
	pthread_mutex_lock(&(phil->t_data->writing));
	action_print(phil, "is eating", "\033[1;35m");
	pthread_mutex_unlock(&(phil->t_data->writing));
	while (phil->t_data->die
		&& mytimer(borntime) - phil->lastmeal < phil->eattime)
		usleep(50);
	if (phil->eatcount > 0)
		(phil->eatcount)--;
	pthread_mutex_unlock(&phil->t_data->mutex[index - 1]);
	pthread_mutex_unlock(&phil->t_data->mutex[index - 1 + k]);
}

void	*simul(void *philo)
{
	static int	id;
	int			index;
	t_param		*phil;

	phil = (t_param *)philo;
	id++;
	index = id;
	phil->index = index;
	if (index % 2 == 0)
		usleep(20000);
	while (phil->t_data->die && phil->eatcount != 0)
	{
		eat(phil, index, phil->borntime);
		sleepfun(phil);
		pthread_mutex_lock(&(phil->t_data->writing));
		action_print(phil, "is thinking", "\033[1;34m");
		pthread_mutex_unlock(&(phil->t_data->writing));
	}
	return (0);
}

void	check_die(t_param **phil, struct timeval borntime)
{
	int	i;
	int	count;

	i = -1;
	count = 1;
	while (1 && (eatcount(phil, &count) != 1))
	{
		while (++i < phil[0]->philnum)
		{
			if (mytimer(borntime) - phil[i]->lastmeal > phil[i]->dietime
				&& phil[i]->eatcount != 0)
			{
				phil[i]->t_data->die = 0;
				pthread_mutex_lock(&(phil[i]->t_data->writing));
				printf("%s%d %d is died\n", "\033[1;31m",
					mytimer(borntime), phil[i]->index);
				pthread_mutex_unlock(&(phil[i]->t_data->writing));
				return ;
			}
		}
		i = -1;
		count = 1;
	}
}

int	thread_creater(int n, t_param **phil)
{
	pthread_t		*id;
	int				i;
	struct timeval	borntime;

	i = 0;
	id = (pthread_t *)malloc(sizeof(pthread_t) * n);
	if (id == NULL)
		return (1);
	gettimeofday(&borntime, NULL);
	while (i < n)
	{
		phil[i]->borntime = borntime;
		pthread_create(&id[i], NULL, &simul, phil[i]);
		usleep(10);
		i++;
	}
	i = -1;
	check_die(phil, borntime);
	while (++i < n)
		pthread_join(id[i], NULL);
	freefunc(phil, n);
	free(id);
	return (0);
}

int	main(int argc, char **argv)
{
	t_param	**phil;
	int		id;
	t_data	t_data;

	if (check(argc, argv) == 1)
		return (0);
	if (argc == 5 || argc == 6)
	{
		id = ft_atoi(argv[1]);
		if (id == 1)
		{
			printf("\033[1;31m%d 1 is died\n", ft_atoi(argv[2]));
			return (0);
		}
		phil = init(argv, &t_data);
		if (phil == 0)
			return (0);
		if (thread_creater(id, phil) == 1)
			return (0);
	}
	else
		printf("There is problem with argument count\n");
	return (0);
}
