/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:33:32 by vagevorg          #+#    #+#             */
/*   Updated: 2022/08/09 22:25:01 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	initmutex(t_param **philo, t_data *t_data, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		if (pthread_mutex_init(&(t_data->mutex[i]), NULL) != 0)
		{
			free(philo);
			free(t_data->mutex);
			while (i > 0)
			{
				i--;
				pthread_mutex_destroy(&(t_data->mutex[i]));
			}
			return (1);
		}
		i++;
	}
	return (0);
}

void	freed(int i, t_param **philo, t_data *t_data)
{
	free(philo);
	free(t_data->mutex);
	while (--i >= 0)
	{
		free(philo[i]);
		pthread_mutex_destroy(&(t_data->mutex[i]));
	}
}

int	initphilo(t_param **philo, t_data *t_data, char **argv, int num)
{
	int	i;

	i = -1;
	while (++i < num)
	{
		philo[i] = (t_param *)malloc(sizeof(t_param));
		if (philo[i] == NULL)
		{
			freed(i, philo, t_data);
			return (1);
		}
		philo[i]->philnum = ft_atoi(argv[1]);
		philo[i]->dietime = ft_atoi(argv[2]);
		philo[i]->eattime = ft_atoi(argv[3]);
		philo[i]->sleeptime = ft_atoi(argv[4]);
		philo[i]->t_data = t_data;
		if (argv[5])
			philo[i]->eatcount = ft_atoi(argv[5]);
		else
			philo[i]->eatcount = -1;
	}
	return (0);
}

t_param	**init(char **argv, t_data *t_data)
{
	int		i;
	t_param	**philo;

	i = 0;
	philo = (t_param **)malloc(sizeof(t_param *) * ft_atoi(argv[1]));
	if (philo == NULL)
		return (0);
	t_data->mutex = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (t_data->mutex == NULL)
	{
		free(philo);
		return (0);
	}
	if ((pthread_mutex_init(&(t_data->writing), NULL)) != 0)
	{
		free(philo);
		free(t_data->mutex);
		return (0);
	}
	if (initmutex(philo, t_data, ft_atoi(argv[1])) == 1
		|| initphilo(philo, t_data, argv, ft_atoi(argv[1])) == 1)
		return (0);
	t_data->die = 1;
	return (philo);
}

int	eatcount(t_param **phil, int *count)
{
	int	i;

	i = 0;
	while (i < phil[0]->philnum)
	{
		if (phil[i]->eatcount == 0)
			*count += 1;
		if (*count == phil[0]->philnum)
		{
			phil[i]->t_data->die = 0;
			return (1);
		}
			i++;
	}
	return (0);
}
