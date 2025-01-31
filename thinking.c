/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 15:13:57 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/12 15:13:59 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	even_wait(t_data *data)
{
	if (data->number_of_philosophers % 2 == 1
		&& data->current_philo_id % 2 == 0
		&& data->p_philos[data->current_philo_id].eat_counter > 0)
		usleep(data->time_to_eat / 2 * 1000);
}

static void	odd_wait(t_data *data)
{
	if (data->current_philo_id % 2 == 1
		&& data->p_philos[data->current_philo_id].eat_counter == 0)
		usleep(data->time_to_eat / 2 * 1000);
}

void	thinking(t_data *data)
{
	print_state_change("is thinking", data);
	odd_wait(data);
	even_wait(data);
}
