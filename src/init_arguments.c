/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:45:54 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/05 14:45:55 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	init_arguments(t_data *data, int argc, char **argv)
{
	(*data).number_of_philosophers = ft_atoi(argv[1]);
	(*data).time_to_die = ft_atoi(argv[2]);
	(*data).time_to_eat = ft_atoi(argv[3]);
	(*data).time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*data).number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		(*data).number_of_times_each_philosopher_must_eat = 0;
	return (0);
}
