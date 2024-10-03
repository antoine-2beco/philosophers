/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:05:59 by ade-beco          #+#    #+#             */
/*   Updated: 2024/10/03 10:58:37 by ade-beco         ###   ########.fr       */
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
		if (i == 1 && k < 2)
			return (printf("Error : At least 2 philosophers\n"), 1);
		if (k > INT32_MAX || k < INT32_MIN)
			return (printf("Error : Argument exceed limits\n"), 1);
	}
	return (0);
}

int	init(int argc, char *argv[])
{
	if (!check_args(argc - 1, argv))
		return (1);
	return (0);
}
