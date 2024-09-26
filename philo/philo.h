/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:44:06 by ade-beco          #+#    #+#             */
/*   Updated: 2024/09/26 11:21:50 by ade-beco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>


//			main.c
int			main(int argc, char *argv[]);

//			init.c
int			init(int argc, char *argv[]);

//			utils.c
int			ft_isdigit(int c);
long int	ft_atoi(const char *str);




#endif