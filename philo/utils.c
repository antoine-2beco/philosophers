/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 09:54:02 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/07 13:22:23 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

long int	ft_atoi(const char *str)
{
	int				n;
	long long int	res;
	long long int	temp;
	size_t			i;

	n = 1;
	res = 0;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
		if (str[i++] == '-')
			n = -n;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = res;
		res = ((res * 10) + (str[i++] - '0'));
		if (temp > res && (n == -1 || n == 1))
			return ((long int)INT32_MAX + 1);
	}
	if (str[i] || (i == 1 && (str[i - 1] == '+' || str[i - 1] == '-')))
		return ((long int)INT32_MAX + 1);
	return (res * n);
}

size_t	get_current_time(t_data *data)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL))
		return (error("Error : Get time failed\n", 0, data));
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_usleep(size_t ms, t_data *data)
{
	size_t	start;

	start = get_current_time(data);
	while ((get_current_time(data) - start) < ms)
		usleep(500);
	return (0);
}
