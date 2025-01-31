/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:44:12 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/05 14:44:14 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fill_further_states(t_data *data)
{
	int	i;

	i = 1;
	while (i < data->number_of_philosophers)
	{
		data[i].number_of_philosophers = data->number_of_philosophers;
		data[i].time_to_die = data->time_to_die;
		data[i].time_to_eat = data->time_to_eat;
		data[i].time_to_sleep = data->time_to_sleep;
		data[i].number_of_times_each_philosopher_must_eat
			= data->number_of_times_each_philosopher_must_eat;
		data[i].p_philos = data->p_philos;
		data[i].p_forks = data->p_forks;
		data[i].p_dead = data->p_dead;
		data[i].current_philo_id = i;
		data[i].start_time = data->start_time;
		i++;
	}
}

void	fill_state(t_data *data)
{
	int				i;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	i = 0;
	while (i < data->number_of_philosophers)
	{
		(*data).p_philos[i].id = i + 1;
		(*data).p_philos[i].eat_counter = 0;
		(*data).p_forks[i].id = i + 1;
		(*data).current_philo_id = 0;
		(*data).p_dead->dead = 0;
		(*data).start_time = (long long)tv.tv_sec
			* (long long)1000000 + (long long)tv.tv_usec;
		(*data).p_philos[i].last_meal = data->start_time;
		i++;
	}
	fill_further_states(data);
}
