/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:59:45 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/07 13:30:01 by ade-beco         ###   ########.fr       */
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

void	*monitor(void *pointer)
{
	t_data	*data;

	data = (t_data *)pointer;
	printf("Monitor started !\n");
	(void) data;
	return (pointer);
}
