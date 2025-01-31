/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:45:37 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/05 14:45:38 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	waiting_time(long time_to_sleep)
{
	struct timeval	tv;
	long long		time_current;
	long long		time_begin;

	gettimeofday(&tv, NULL);
	time_begin = (long long)tv.tv_sec
		* (long long)1000000 + (long long)tv.tv_usec;
	time_current = time_begin;
	while (time_current - time_begin < time_to_sleep)
	{
		usleep(20);
		gettimeofday(&tv, NULL);
		time_current = (long long)tv.tv_sec
			* (long long)1000000 + (long long)tv.tv_usec;
	}
}
