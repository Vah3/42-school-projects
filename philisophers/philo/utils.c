/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vagevorg <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/04 17:40:22 by vagevorg          #+#    #+#             */
/*   Updated: 2022/08/09 22:28:51 by vagevorg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phil.h"

int	ft_atoi(const char *str)
{
	int	index;
	int	convert;
	int	sign;

	index = 0;
	convert = 0;
	sign = 1;
	while ((str[index] >= 9 && str[index] <= 13) || str[index] == 32)
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -sign;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		convert = convert * 10 + str[index] - '0';
		index++;
	}
	return (sign * convert);
}

int	mytimer(struct timeval borntime)
{
	struct timeval	current;
	int				time;

	gettimeofday(&current, NULL);
	time = ((current.tv_usec - borntime.tv_usec)) / 1000
		+ ((current.tv_sec - borntime.tv_sec) * 1000);
	return (time);
}

void	action_print(t_param *phil, char *string, char *color)
{
	if (phil->t_data->die)
	{
		printf("%s", color);
		printf("%d %d %s\n", mytimer(phil->borntime), phil->index, string);
	}
}

void	sleepfun(t_param *phil)
{
	int	sleepstart;

	sleepstart = mytimer(phil->borntime);
	pthread_mutex_lock(&(phil->t_data->writing));
	action_print(phil, "is sleeping", "\033[1;32m");
	pthread_mutex_unlock(&(phil->t_data->writing));
	while (phil->t_data->die)
	{
		if (mytimer(phil->borntime) - sleepstart >= phil->sleeptime)
			break ;
		usleep(50);
	}
}

int	check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 5 || argc == 6)
	{
		if (ft_atoi(argv[1]) < 1 || ft_atoi(argv[2]) <= 0
			|| ft_atoi(argv[3]) <= 0 || ft_atoi(argv[4]) <= 0)
		{
			printf("wrong >	_para,|gcetr\n");
			i = 1;
		}
		if (argc == 6 && ft_atoi(argv[5]) <= 0)
		{
			printf("wrong eat count\n");
			i = 1;
		}
	}
	else
		printf("There is problem with argument count\n");
	return (i);
}
