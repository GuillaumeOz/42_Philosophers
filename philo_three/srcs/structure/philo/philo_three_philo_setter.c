/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_philo_setter.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:07 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/11 14:24:56 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void			set_philo_id(t_philo *philo, pid_t value)
{
	philo->id = value;
}

void			set_philo_died(t_philo *philo, bool value)
{
	philo->died = value;
}

void			set_philo_nb_eat(t_philo *philo, int value)
{
	philo->nb_eat += value;
}

void			set_philo_time_to_die(t_philo *philo, int value)
{
	philo->time_die += value;
}
