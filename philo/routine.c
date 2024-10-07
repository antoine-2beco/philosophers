/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:59:47 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/07 16:54:10 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	p_eat(t_philos *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_status("has taken a fork", philo);
	if (philo->data->n_philos == 1)
	{
		ft_usleep(philo->time_to_die, philo->data);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print_status("has taken a fork", philo);
	philo->eating = 1;
	print_status("is eating", philo);
	pthread_mutex_lock(philo->eat_lock);
	philo->last_meal = get_current_time(philo->data);
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->eat_lock);
	ft_usleep(philo->time_to_eat, philo->data);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

static void	p_sleep(t_philos *philo)
{
	print_status("is sleeping", philo);
	ft_usleep(philo->time_to_sleep, philo->data);
}

static void	p_think(t_philos *philo)
{
	print_status("is thinking", philo);
}

void	*routine(void *pointer)
{
	t_philos	*philo;

	philo = (t_philos *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1, philo->data);
	while (!dead_philo(philo))
	{
		p_eat(philo);
		p_sleep(philo);
		p_think(philo);
	}
	return ((void*)0);
}
