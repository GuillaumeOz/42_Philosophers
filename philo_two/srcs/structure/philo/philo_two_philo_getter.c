/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two_philo_getter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:01 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/04 16:12:11 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

int				get_philo_id(t_philo *philo)
{
	return (philo->id);
}

pthread_t		*get_philo_thread(t_philo *philo)
{
	return (philo->thread);
}

bool 			get_philo_died(t_philo *philo)
{
	return (philo->died);
}

int 			get_philo_nb_eat(t_philo *philo)
{
	return (philo->nb_eat);
}
