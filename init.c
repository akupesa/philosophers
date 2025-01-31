/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:46:10 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/05 14:46:11 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_structs(t_data *data)
{
	(*data).p_philos = (t_philos *)
		malloc((data->number_of_philosophers) * sizeof(t_philos));
	if ((*data).p_philos == NULL)
		return (printf("malloc of p_philos failed.\n"), -1);
	(*data).p_forks = (t_fork *)
		malloc(data->number_of_philosophers * sizeof(t_fork));
	if ((*data).p_forks == NULL)
		return (printf("malloc of p_forks failed.\n"), -1);
	(*data).p_dead = (t_dead *)malloc(sizeof(t_dead));
	if ((*data).p_dead == NULL)
		return (printf("malloc of p_dead failed.\n"), -1);
	fill_state(data);
	return (0);
}

static int	init_fork_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->p_forks[i].mutex, NULL) != 0)
		{
			printf("mutex init failed.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	init_philo_mutexes(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		if (pthread_mutex_init(&data->p_philos[i].mutex, NULL) != 0)
		{
			printf("mutex init failed.\n");
			return (-1);
		}
		i++;
	}
	return (0);
}

static int	init_dead_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->p_dead->mutex, NULL) != 0)
	{
		printf("mutex init failed.\n");
		return (-1);
	}
	return (0);
}

int	init(t_data *data, int argc, char **argv)
{
	if (init_arguments(data, argc, argv) == -1 || init_structs(data) == -1)
		return (-1);
	if (init_fork_mutexes(data) == -1)
		return (-1);
	if (init_philo_mutexes(data) == -1)
		return (-1);
	if (init_dead_mutex(data) == -1)
		return (-1);
	return (1);
}
