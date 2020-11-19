/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_philo_address_getter.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 18:30:27 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/19 14:43:55 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

t_time			*get_philo_time_addr(t_philo *philo)
{
    return (philo->time);
}

t_state			*get_philo_state_addr(t_philo *philo)
{
    return (philo->state);
}

t_philo			*get_philo_previous_addr(t_philo *philo)
{
    return (philo->previous);
}

t_philo			*get_philo_next_addr(t_philo *philo)
{
    return (philo->next);
}