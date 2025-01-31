/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_change.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:13:32 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/12 15:13:34 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_state_change(char *message, t_data *data)
{
	struct timeval	tv;
	long long		time_stamp;

	gettimeofday(&tv, NULL);
	time_stamp = (long long)tv.tv_sec
		* (long long)1000000 + (long long)tv.tv_usec - data->start_time;
	printf("%lli %i %s\n", time_stamp / 1000,
		data->current_philo_id + 1, message);
	pthread_mutex_unlock(&data->p_dead->mutex);
}
