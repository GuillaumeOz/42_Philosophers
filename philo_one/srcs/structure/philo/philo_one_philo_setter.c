/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_philo_setter.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:07 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/17 22:02:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void			set_philo_id(t_philo *philo, int value)
{
	philo->id = value;
}

void			set_philo_thread(t_philo *philo)
{
	pthread_mutex_init(philo->fork, NULL);
}

void			set_philo_fork(t_philo *philo)
{
	pthread_mutex_init(philo->fork, NULL);
}

void			set_philo_died(t_philo *philo)
{
	philo->died = false;
}

void			set_philo_error_philo(t_philo *philo)
{
	philo->error_philo = false;
}
