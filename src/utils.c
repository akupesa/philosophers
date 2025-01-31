/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:44:57 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/05 14:44:58 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	is_digits(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

static int	is_there_a_signal(const char *str, int *signal)
{
	int		i;

	i = 0;
	while ((str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			*signal = 1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	start;
	int	signal;
	int	res;
	int	i;

	i = 0;
	signal = 0;
	res = 0;
	start = is_there_a_signal(str, &signal);
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
		i++;
	i = 0;
	while (str[start] >= '0' && str[start] <= '9'
		&& str[start] != '\0')
	{
		res = (res * 10) + (str[start] - 48);
		i++;
		start++;
	}
	if (signal == 1)
		res = res * -1;
	return (res);
}
