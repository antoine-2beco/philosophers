/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:59:45 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/14 11:34:46 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *str, t_philos *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time(philo->data) - philo->start_time;
	if (!*philo->dead)
		printf("%zu %i %s\n", time, (philo->id + 1), str);
	pthread_mutex_unlock(philo->write_lock);
}

static int	check_dead_philo(t_philos *philo)
{
	pthread_mutex_lock(philo->eat_lock);
	if ((get_current_time(philo->data) - philo->last_meal) >= \
			philo->time_to_die && philo->eating == 0)
		return (pthread_mutex_unlock(philo->eat_lock), 1);
	pthread_mutex_unlock(philo->eat_lock);
	return (0);
}

static int	check_deads_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		if (check_dead_philo(&data->philos[i]))
		{
			print_status("died", &data->philos[i]);
			pthread_mutex_lock(&data->dead_lock);
			*data->philos[i].dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
			return (1);
		}
	}
	return (0);
}

static int	check_eaten_meals(t_data *data)
{
	int	i;
	int	finished_eat;

	i = -1;
	finished_eat = 0;
	if (data->n_times_to_eat == -1)
		return (0);
	while (++i < data->n_philos)
	{
		pthread_mutex_lock(&data->dead_lock);
		if (data->philos[i].meals_eaten >= data->n_times_to_eat)
			finished_eat++;
		pthread_mutex_unlock(&data->dead_lock);
	}
	if (finished_eat == data->n_philos)
	{
		pthread_mutex_lock(&data->dead_lock);
		data->dead = 1;
		pthread_mutex_unlock(&data->dead_lock);
		return (1);
	}
	return (0);
}

void	*monitor(void *pointer)
{
	t_data	*data;

	data = (t_data *)pointer;
	while (1)
	{
		if (check_deads_philos(data) || check_eaten_meals(data))
			break ;
	}
	return (pointer);
}
