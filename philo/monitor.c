/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:59:45 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/07 15:21:47 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(char *str, t_philos *philo)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = get_current_time(philo->data) - philo->start_time;
	if (!dead_loop(philo))
		printf("%zu %i %s\n", time, philo->id, str);
	pthread_mutex_unlock(philo->write_lock);
}

int	dead_loop(t_philos *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

static int	check_deads_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		pthread_mutex_lock(&data->eat_lock);
		if ((get_current_time(data) - data->philos[i].last_meal) >= \
				data->time_to_die && data->philos[i].eating == 0)
		{
			pthread_mutex_unlock(&data->eat_lock);
			print_status("died", &data->philos[i]);
			pthread_mutex_lock(&data->dead_lock);
			*data->philos[i].dead = 1;
			pthread_mutex_unlock(&data->dead_lock);
			return (1);
		}
		else
			pthread_mutex_unlock(&data->eat_lock);
	}
	return (0);
}

void	*monitor(void *pointer)
{
	t_data	*data;

	data = (t_data *)pointer;
	while (1)
	{
		if (check_deads_philos(data))
			break;
	}
	return (pointer);
}
