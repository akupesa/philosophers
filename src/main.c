/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:12:06 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/12 15:12:08 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	arguments_counter(int argc)
{
	if (argc < 5 || argc > 6)
	{
		if (argc < 5)
			printf("Not enought arguments!\n");
		else
			printf("Too many arguments!\n");
		return (-1);
	}
	return (0);
}

int	arguments_validator(int argc, char **argv)
{
	if (ft_atoi(argv[1]) <= 0 || is_digits(argv[1]) <= 0)
		return (-1);
	if (ft_atoi(argv[2]) <= 0 || ft_atoi(argv[3]) <= 0
		|| ft_atoi(argv[4]) <= 0 || is_digits(argv[2]) == 0
		|| is_digits(argv[3]) == 0 || is_digits(argv[4]) == 0)
	{
		printf("Some invalid arguments. Please insert valid arguments.\n");
		return (-1);
	}
	if (argc == 6 && (ft_atoi(argv[5]) <= 0 || is_digits(argv[5]) == 0))
		return (-1);
	return (0);
}

void	deinit_structs(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_mutex_destroy(&data->p_philos[i].mutex);
		i++;
	}
	pthread_mutex_destroy(&data->p_dead->mutex);
	free(data->p_philos);
	free(data->p_forks);
	free(data->p_dead);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	pthread_t	*philo_threads;

	if (arguments_counter(argc) == -1
		|| arguments_validator(argc, argv) == -1)
		return (-1);
	data = (t_data *) malloc(ft_atoi(argv[1]) * sizeof(t_data));
	if (data == NULL)
		return (printf("malloc of data failed.\n"), -1);
	if (init(data, argc, argv) == -1)
		return (-1);
	if (init_threads(data, &philo_threads) == -1)
		return (-1);
	if (create_threads(data, philo_threads) == -1)
		return (-1);
	while (is_program_closed(data) == 0)
	{
		waiting_time(9000);
	}
	wait_for_threads(data, philo_threads);
	deinit_structs(data);
	free(data);
	free(philo_threads);
	return (0);
}
