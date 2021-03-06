/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_t_philo.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 18:21:21 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/06 23:05:03 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_T_PHILO_H
# define PHILO_T_PHILO_H

typedef struct s_philo
{
	int				id;
	pthread_t		*thread;
	pthread_mutex_t	*fork_mutex;
	int				nb_eat;
	int				time_die;
	bool			died;
	bool			error_philo;
	t_time			*time;
	t_state			*state;
	struct s_philo	*next;
	struct s_philo	*previous;
}				t_philo;

/*
** Choice of fork
*/

typedef enum e_fork_choice
{
	RIGHT_FORK,
	LEFT_FORK,
}				t_fork_choice;

/*
**	t_time Constructor - Destructor
*/

t_philo			*malloc_philo(t_time *time, t_state *state);
void			create_philo(t_philo *philo, t_time *time,
					t_state *state, int id);
void			create_philo_link(t_philo **tmp, t_philo *philo);
void			destroy_philo(t_philo state);
void			free_philo(t_philo *state);

/*
**	t_state Getter - Setter
*/

int				get_philo_id(t_philo *philo);
pthread_t		*get_philo_thread(t_philo *philo);
pthread_mutex_t	*get_philo_fork(t_philo *philo, t_fork_choice fork_choice);
int				get_philo_nb_eat(t_philo *philo);
int				get_philo_time_to_die(t_philo *philo);
bool			get_philo_died(t_philo *philo);

t_time			*get_philo_time_addr(t_philo *philo);
t_state			*get_philo_state_addr(t_philo *philo);
t_philo			*get_philo_previous_addr(t_philo *philo);
t_philo			*get_philo_next_addr(t_philo *philo);
bool			get_philo_error_philo(t_philo *philo);

void			set_philo_thread(t_philo *philo);
void			set_philo_mutex(t_philo *philo);
void			set_philo_died(t_philo *philo, bool value);
void			set_philo_time_to_die(t_philo *philo, int value);
void			set_philo_nb_eat(t_philo *philo, int value);

#endif
