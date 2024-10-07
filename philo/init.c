/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:05:59 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/07 14:15:50 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int n_arg, char *argv[])
{
	int			i;
	int			j;
	long int	k;

	i = 0;
	if (n_arg < 4)
		return (printf("Error : Not enough arguments\n"), 1);
	else if (n_arg > 5)
		return (printf("Error : Too much arguments\n"), 1);
	while (++i <= n_arg)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!ft_isdigit(argv[i][j]))
				return (printf("Error : Bad arguments (only digits)\n"), 1);
		}
		k = ft_atoi(argv[i]);
		if (k > INT32_MAX || k < INT32_MIN)
			return (printf("Error : Argument exceed limits\n"), 1);
	}
	return (0);
}

int	init_data(t_data *data, int i, char *argv[])
{
	data->dead = 0;
	data->n_philos = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->n_times_to_eat = 0;
	if (i == 5)
		data->n_times_to_eat = ft_atoi(argv[5]);
	data->philos = malloc((sizeof(t_philos) * data->n_philos));
	if (!data->philos)
		return (error(MALLOC_ERROR, -1, data));
	data->forks = malloc((sizeof(pthread_mutex_t) * data->n_philos));
	if (!data->forks)
		return (error(MALLOC_ERROR, 1, data));
	if (pthread_mutex_init(&data->write_lock, NULL))
		return (error(MUTEX_ERROR, 2, data));
	if (pthread_mutex_init(&data->eat_lock, NULL))
		return (error(MUTEX_ERROR, 3, data));
	if (pthread_mutex_init(&data->dead_lock, NULL))
		return (error(MUTEX_ERROR, 4, data));
	i = -1;
	while (++i < data->n_philos)
		if (pthread_mutex_init(&data->forks[i], NULL))
			return (error(MUTEX_ERROR, (i + 5), data));
	return (0);
}

int	init_philos(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->n_philos)
	{
		data->philos[i].id = i;
		data->philos[i].start_time = get_current_time(data);
		data->philos[i].last_meal = get_current_time(data);
		data->philos[i].time_to_die = data->time_to_die;
		data->philos[i].time_to_eat = data->time_to_eat;
		data->philos[i].time_to_sleep = data->time_to_sleep;
		data->philos[i].eating = 0;
		data->philos[i].meals_eaten = 0;
		data->philos[i].dead = &data->dead;
		data->philos[i].write_lock = &data->write_lock;
		data->philos[i].eat_lock = &data->eat_lock;
		data->philos[i].dead_lock = &data->dead_lock;
		data->philos[i].l_fork = &data->forks[i];
		if (i == 0)
			data->philos[0].r_fork = &data->forks[data->n_philos - 1];
		else
			data->philos[i].r_fork = &data->forks[i - 1];
		data->philos[i].data = data;
	}
	return (0);
}

int	init_threads(t_data *data)
{
	int	i;

	i = -1;
	if (pthread_create(&data->monitor, NULL, &monitor, data))
		return (error("Error : Thread creation failed\n", 0, data));
	while (++i < data->n_philos)
		if (pthread_create(&data->philos[i].threads, NULL, \
				&routine, &data->philos[i]))
			return (error("Error : Thread creation failed\n", 0, data));
	i = -1;
	if (pthread_join(data->monitor, NULL))
		return (error("Error : Thread join failed\n", 0, data));
	while (++i < data->n_philos)
		if (pthread_join(data->philos[i].threads, NULL))
			return (error("Error : Thread join failed\n", 0, data));
	return (0);
}
