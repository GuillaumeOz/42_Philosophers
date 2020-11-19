/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one_philo_constructor_destructor.c           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 19:38:39 by gozsertt          #+#    #+#             */
/*   Updated: 2020/11/19 19:58:33 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static void test(t_philo *first)
{
	int		i;

	i = -1;
	while (++i < 9)
	{
		PRINTD(first->id)
		first = first->next;
	}
}

t_philo	*malloc_philo(t_time *time, t_state *state)
{
	t_philo	*philo;
	t_philo	*first;
	t_philo *tmp;
	int		i;

	i = -1;
	tmp = NULL;
	while(++i < state->nb_philo)
	{
		philo = (t_philo*)malloc(sizeof(t_philo));
		if (philo == NULL)
		{
			error_msg("Error: malloc_philo failed");
			philo->error_philo = true;
			return (NULL);
		}
		if (i == 0)
			first = philo;
		create_philo(philo, time, state, i + 1);
		create_philo_link(tmp, philo);
	}
	first->previous = philo;
	philo->next = first;
	test(first);
	return (first);
}

void	create_philo_link(t_philo *tmp, t_philo *philo)
{
	if (tmp == NULL)
	{
		tmp = philo;
		return ;
	}
	tmp->next = philo;
	philo->previous = tmp;
	tmp = philo;
}

void	create_philo(t_philo *philo, t_time *time, t_state *state, int id)
{
	set_philo_id(philo, id);
	set_philo_fork(&philo);
	set_philo_died(philo);
	set_philo_error_philo(philo);
	philo->time = time;
	philo->state = state;
}

void	destroy_philo(t_philo philo)
{
	pthread_mutex_destroy(philo.fork);
}

void	free_philo(t_philo *philo)
{
	t_state	*state;
	t_philo	*tmp;
	int		i;

	i = -1;
	state = get_philo_state_addr(philo);
	while(++i < get_state_nb_philo_fork(state, PHILO))
	{
		tmp = get_philo_next_addr(philo);
		destroy_philo(*philo);
		free(philo);
		philo = tmp;
	}
}