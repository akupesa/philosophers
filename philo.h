/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akupesa <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 20:30:06 by akupesa           #+#    #+#             */
/*   Updated: 2025/01/04 20:30:10 by akupesa          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos
{
	int				id;
	int				eat_counter;
	long long		last_meal;
	pthread_mutex_t	mutex;

}	t_philos;

typedef struct s_fork
{
	int				id;
	pthread_mutex_t	mutex;

}	t_fork;

typedef struct s_dead
{
	int				dead;
	pthread_mutex_t	mutex;

}	t_dead;

typedef struct s_data
{
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				current_philo_id;
	int				number_of_philosophers;
	int				number_of_times_each_philosopher_must_eat;
	long long		start_time;
	t_fork			*p_forks;
	t_dead			*p_dead;
	t_philos		*p_philos;
}	t_data;

int		is_digits(char *str);
int		ft_atoi(const char *str);
int		is_dead_flag(t_data *data);
int		acquire_forks(t_data *data);
int		is_program_closed(t_data *data);
int		init(t_data *data, int argc, char **argv);
int		am_i_dead(t_data *data, struct timeval *tv);
int		init_arguments(t_data *data, int argc, char **argv);
int		create_threads(t_data *data, pthread_t *philo_threads);
int		wait_for_threads(t_data *data, pthread_t *philo_threads);
int		init_threads(t_data *data, pthread_t	**philo_threads);
void	thinking(t_data *data);
void	*philo_thread(void *arg);
void	fill_state(t_data *data);
void	release_forks(t_data *data);
void	waiting_time(long time_to_sleep);
void	print_state_change(char *message, t_data *data);
void	print_state_change(char *message, t_data *data);

#endif