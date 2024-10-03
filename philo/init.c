/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:05:59 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/03 12:20:42 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_args(int n_arg, char *argv[])
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
		if (i == 1 && k < 2)
			return (printf("Error : At least 2 philosophers\n"), 1);
		if (k > INT32_MAX || k < INT32_MIN)
			return (printf("Error : Argument exceed limits\n"), 1);
	}
	return (0);
}

static int	init_data(t_data *data, int argc, char *argv[])
{
	int	n_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_times_to_eat;

	n_philos = ft_atoi(argv[1]);
	time_to_die = ft_atoi(argv[2]);
	time_to_eat = ft_atoi(argv[3]);
	time_to_sleep = ft_atoi(argv[4]);
	if (argc == 5)
		n_times_to_eat = ft_atoi(argv[5]);
	else
		n_times_to_eat = 0;
	pthread_mutex_init(&data->write_lock, NULL);
	pthread_mutex_init(&data->sleep_lock, NULL);
	pthread_mutex_init(&data->think_lock, NULL);
	data->dead = 0;
	(void)n_philos;
	(void)time_to_die;
	(void)time_to_eat;
	(void)time_to_sleep;
	(void)n_times_to_eat;
	return (0);
}

int	init(t_data *data, int argc, char *argv[])
{
	if (check_args(argc - 1, argv))
		return (1);
	if (init_data(data, argc - 1, argv))
		return (1);
	return (0);
}
