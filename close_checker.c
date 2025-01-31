/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:53:29 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/05 14:53:31 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_must_eat_reached(t_data *data, int *must_eat_reached)
{
	if (data->number_of_times_each_philosopher_must_eat != 0
		&& *must_eat_reached == 1)
	{
		pthread_mutex_lock(&data->p_dead->mutex);
		data->p_dead->dead = 1;
		pthread_mutex_unlock(&data->p_dead->mutex);
		return (1);
	}
	return (0);
}

static void	set_must_eat_reached(t_data *data, int *must_eat_reached, int i)
{
	if (data->number_of_times_each_philosopher_must_eat != 0
		&& data[i].p_philos[i].eat_counter
		< data->number_of_times_each_philosopher_must_eat)
		*must_eat_reached = 0;
}

static int	is_dead(t_data *data, struct timeval *tv,
	int *must_eat_reached, int i)
{
	long long	time_stamp;

	while (i < data->number_of_philosophers)
	{
		pthread_mutex_lock(&data[i].p_philos[i].mutex);
		gettimeofday(tv, NULL);
		if (((long long)tv->tv_sec * 1000000LL + (long long)tv->tv_usec)
			- data[i].p_philos[i].last_meal
			> (long long)data->time_to_die * (long long)1000)
		{
			pthread_mutex_lock(&data->p_dead->mutex);
			data->p_dead->dead = 1;
			time_stamp = (long long)tv->tv_sec * (long long)1000000
				+ (long long)tv->tv_usec - data->start_time;
			printf("%lli %i died\n", time_stamp / 1000, data[i].p_philos[i].id);
			pthread_mutex_unlock(&data->p_dead->mutex);
			pthread_mutex_unlock(&data[i].p_philos[i].mutex);
			return (1);
		}
		set_must_eat_reached(data, must_eat_reached, i);
		pthread_mutex_unlock(&data[i].p_philos[i].mutex);
		i++;
	}
	return (0);
}

int	is_program_closed(t_data *data)
{
	int				i;
	int				must_eat_reached;
	struct timeval	tv;

	must_eat_reached = 1;
	i = 0;
	if (is_dead(data, &tv, &must_eat_reached, i) == 1)
		return (1);
	if (is_must_eat_reached(data, &must_eat_reached) == 1)
		return (1);
	return (0);
}
