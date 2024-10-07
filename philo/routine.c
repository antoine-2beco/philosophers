/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 11:59:47 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/07 13:29:31 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	p_think(t_philos *philo)
{
	print_status("is thinking", philo);
}

void	p_sleep(t_philos *philo)
{
	print_status("is sleeping", philo);
	ft_usleep(philo->time_to_sleep, philo->data);
}

void	*routine(void *pointer)
{
	t_philos	*philo;

	philo = (t_philos *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1, philo->data);
	while (!dead_loop(philo))
	{
		p_think(philo);
		p_sleep(philo);
	}
	return (pointer);
}
