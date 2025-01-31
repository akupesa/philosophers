/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:44:39 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/05 14:44:40 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	quire_forks_without_last(t_data *data)
{
	pthread_mutex_lock(&data->p_forks[data->current_philo_id].mutex);
	if (is_dead_flag(data) == 0)
		print_state_change("has taken a fork", data);
	else
	{
		pthread_mutex_unlock(&data->p_forks[data->current_philo_id].mutex);
		return (0);
	}
	pthread_mutex_lock(&data->p_forks[(data->current_philo_id + 1)
		% data->number_of_philosophers].mutex);
	if (is_dead_flag(data) == 0)
		print_state_change("has taken a fork", data);
	else
	{
		pthread_mutex_unlock(&data->p_forks[(data->current_philo_id + 1)
			% data->number_of_philosophers].mutex);
		pthread_mutex_unlock(&data->p_forks[data->current_philo_id].mutex);
		return (0);
	}
	return (1);
}

static int	aquire_forks_last_philo(t_data *data)
{
	pthread_mutex_lock(&data->p_forks[(data->current_philo_id + 1)
		% data->number_of_philosophers].mutex);
	if (is_dead_flag(data) == 0)
		print_state_change("has taken a fork", data);
	else
	{
		pthread_mutex_unlock(&data->p_forks[(data->current_philo_id + 1)
			% data->number_of_philosophers].mutex);
		return (0);
	}
	pthread_mutex_lock(&data->p_forks[data->current_philo_id].mutex);
	if (is_dead_flag(data) == 0)
		print_state_change("has taken a fork", data);
	else
	{
		pthread_mutex_unlock(
			&data->p_forks[data->current_philo_id].mutex);
		pthread_mutex_unlock(&data->p_forks[(data->current_philo_id + 1)
			% data->number_of_philosophers].mutex);
		return (0);
	}
	return (1);
}

void	release_forks(t_data *data)
{
	if (data->current_philo_id + 1 == data->number_of_philosophers)
	{
		pthread_mutex_unlock(&data->p_forks[(data->current_philo_id + 1)
			% data->number_of_philosophers].mutex);
		pthread_mutex_unlock(&data->p_forks[data->current_philo_id].mutex);
	}
	else
	{
		pthread_mutex_unlock(&data->p_forks[data->current_philo_id].mutex);
		pthread_mutex_unlock(&data->p_forks[(data->current_philo_id + 1)
			% data->number_of_philosophers].mutex);
	}
}

int	acquire_forks(t_data *data)
{
	if (data->current_philo_id % 2 == 0)
		return (quire_forks_without_last(data));
	else
		return (aquire_forks_last_philo(data));
}
