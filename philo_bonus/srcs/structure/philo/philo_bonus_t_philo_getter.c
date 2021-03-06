/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_t_philo_getter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:39:01 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/01 01:58:51 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	get_philo_id(t_philo *philo)
{
	return (philo->id);
}

bool	get_philo_died(t_philo *philo)
{
	return (philo->died);
}

int	get_philo_nb_eat(t_philo *philo)
{
	return (philo->nb_eat);
}
