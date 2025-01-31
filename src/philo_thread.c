/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:12:49 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/12 15:12:53 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_dont_start_eating(t_data *data, struct timeval *tv)
{
	if (am_i_dead(data, tv) == 1)
	{
		pthread_mutex_lock(&data->p_dead->mutex);
		data->p_dead->dead = 1;
		pthread_mutex_unlock(&data->p_dead->mutex);
		release_forks(data);
		pthread_mutex_unlock(&data->p_philos[data->current_philo_id].mutex);
		return (1);
	}
	return (0);
}

static int	eating(t_data *data)
{
	struct timeval	tv;

	pthread_mutex_lock(&data->p_philos[data->current_philo_id].mutex);
	gettimeofday(&tv, NULL);
	if (is_dont_start_eating(data, &tv) == 1)
		return (0);
	(*data).p_philos[data->current_philo_id].last_meal
		= (long long)tv.tv_sec * (long long)1000000 + (long long)tv.tv_usec;
	if ((*data).p_philos[data->current_philo_id].last_meal - data->start_time
		< data->time_to_eat / 2 * 1000)
		(*data).p_philos[data->current_philo_id].last_meal
			= data->start_time;
	(*data).p_philos[data->current_philo_id].eat_counter++;
	pthread_mutex_unlock(&data->p_philos[data->current_philo_id].mutex);
	if (is_dead_flag(data) == 0)
		print_state_change("is eating", data);
	else
	{
		release_forks(data);
		return (0);
	}
	waiting_time(data->time_to_eat * 1000);
	return (1);
}

void	*philo_thread(void *arg)
{
	t_data			*data;

	data = (t_data *)arg;
	while (1)
	{
		if (is_dead_flag(data) == 0)
			thinking(data);
		else
			return (NULL);
		if (data->number_of_philosophers == 1)
			return (NULL);
		if (acquire_forks(data) == 0)
			return (NULL);
		if (eating(data) == 1)
			release_forks(data);
		else
			return (NULL);
		if (is_dead_flag(data) == 0)
			print_state_change("is sleeping", data);
		else
			return (NULL);
		waiting_time(data->time_to_sleep * 1000);
	}
	return (NULL);
}
