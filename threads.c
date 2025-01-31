/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:14:31 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/12 15:14:33 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_for_threads(t_data *data, pthread_t *philo_threads)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_join(philo_threads[i], NULL) != 0)
		{
			printf("pthread_join failed.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	create_threads(t_data *data, pthread_t *philo_threads)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_create(&philo_threads[i], NULL,
				(void *(*)(void *))philo_thread, (void *) &data[i]) != 0)
		{
			printf("pthread_create failed.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

int	init_threads(t_data *data, pthread_t	**philo_threads)
{
	*philo_threads = (pthread_t *) malloc(data->number_of_philosophers
			* sizeof(pthread_t));
	if (*philo_threads == NULL)
	{
		printf("malloc of philo_threads failed.\n");
		return (-1);
	}
	return (0);
}
