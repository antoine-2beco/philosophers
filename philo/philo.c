/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:43:33 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/03 16:41:00 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	free_data(t_data *data, int mode)
{
	int	i;

	i = -1;
	if (mode >= 0)
		free(data->philos);
	if (mode > 1 || mode == 0)
		free(data->forks);
	if (mode > 2 || mode == 0)
		pthread_mutex_destroy(&data->write_lock);
	if (mode > 3 || mode == 0)
		pthread_mutex_destroy(&data->sleep_lock);
	if (mode > 4 || mode == 0)
		pthread_mutex_destroy(&data->think_lock);
	while (++i < data->n_philos && (mode > (i + 5) || mode == 0))
		pthread_mutex_destroy(&data->forks[i]);
	return (0);
}

// to free philos forks (mutex?)
int	error(char *error_mess, int mode, t_data *data)
{
	printf("%s\n", error_mess);
	free_data(data, mode);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (init(&data, argc, argv))
		return (1);
	free_data(&data, 0);
	return (0);
}
