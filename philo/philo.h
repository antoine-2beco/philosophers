/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:44:06 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/14 11:27:55 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

//			structs
struct	s_data;

typedef struct s_philos
{
	pthread_t			threads;
	int					id;

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
	pthread_mutex_t		*eat_lock;
	pthread_mutex_t		*dead_lock;

	struct s_data		*data;
}						t_philos;

typedef struct s_data
{
	t_philos			*philos;
	pthread_mutex_t		*forks;
	pthread_t			monitor;

	int					dead;
	int					n_philos;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	int					n_times_to_eat;

	pthread_mutex_t		write_lock;
	pthread_mutex_t		eat_lock;
	pthread_mutex_t		dead_lock;
}						t_data;

//			main.c
int			error(char *error_mess, long int mode, t_data *data);;
int			main(int argc, char *argv[]);

//			init.c
int			check_args(int n_arg, char *argv[]);
int			init_data(t_data *data, int i, char *argv[]);
int			init_philos(t_data *data);
int			init_threads(t_data *data);

//			monitor.c
void		print_status(char *str, t_philos *philo);
void		*monitor(void *pointer);

//			philo_routine.c
void		*routine(void *pointer);

//			utils.c
int			ft_isdigit(int c);
long int	ft_atoi(const char *str);
size_t		get_current_time(t_data *data);
int			ft_usleep(size_t ms, t_data *data);

#endif