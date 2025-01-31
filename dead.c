/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:13:10 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/12 15:13:11 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_dead_flag(t_data *data)
{
	pthread_mutex_lock(&data->p_dead->mutex);
	if (data->p_dead->dead == 1)
	{
		pthread_mutex_unlock(&data->p_dead->mutex);
		return (1);
	}
	return (0);
}

int	am_i_dead(t_data *data, struct timeval *tv)
{
	if (((long long)tv->tv_sec * 1000000LL + (long long)tv->tv_usec)
		- data->p_philos[data->current_philo_id].last_meal
		> (long long)data->time_to_die * (long long)1000)
		return (1);
	return (0);
}
