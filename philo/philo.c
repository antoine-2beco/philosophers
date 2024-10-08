/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:43:33 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/07 16:43:28 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	free_data(t_data *data, long int mode)
{
	long int	i;

	i = -1;
	if (mode >= 0)
		free(data->philos);
	if (mode > 1 || mode == 0)
		free(data->forks);
	if (mode > 2 || mode == 0)
		pthread_mutex_destroy(&data->write_lock);
	if (mode > 3 || mode == 0)
		pthread_mutex_destroy(&data->eat_lock);
	if (mode > 4 || mode == 0)
		pthread_mutex_destroy(&data->dead_lock);
	while (++i < data->n_philos && (mode > (i + 5) || mode == 0))
		pthread_mutex_destroy(&data->forks[i]);
	return (0);
}

int	error(char *error_mess, long int mode, t_data *data)
{
	printf("%s\n", error_mess);
	free_data(data, mode);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (check_args(argc - 1, argv))
		return (1);
	if (init_data(&data, argc - 1, argv))
		return (1);
	if (init_philos(&data))
		return (1);
	if (init_threads(&data))
		return (1);
	free_data(&data, 0);
	return (0);
}
