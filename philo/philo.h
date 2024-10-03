/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:44:06 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/03 12:21:56 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>

//			structs

typedef struct s_philos
{
	pthread_t			thread;
	int					id;
	int					n_philos;
	int					n_times_to_eat;

	size_t				start_time;
	size_t				last_meal;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;

	int					eating;
	int					meals_eaten;
	int					*dead;

	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*sleep_lock;
	pthread_mutex_t		*think_lock;
}						t_philos;

typedef struct s_data
{
	t_philos			*philos;

	int					dead;
	pthread_mutex_t		write_lock;
	pthread_mutex_t		sleep_lock;
	pthread_mutex_t		think_lock;
}						t_data;

//			main.c
int			main(int argc, char *argv[]);

//			init.c
int			init(t_data *data, int argc, char *argv[]);

//			utils.c
int			ft_isdigit(int c);
long int	ft_atoi(const char *str);

#endif