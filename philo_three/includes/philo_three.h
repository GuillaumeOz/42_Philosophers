/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:10:17 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/16 14:01:05 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <pthread.h>
# include <semaphore.h>
# include <sys/types.h>
# include <signal.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <sys/time.h>
# include <stdio.h>
# include <string.h>
# include <inttypes.h>
# include <fcntl.h>
# include <sys/stat.h>

# include "philo_three_time.h"
# include "philo_three_state.h"
# include "philo_three_philo.h"

/*
** Constructor error handling
*/

typedef enum	e_error
{
	ERROR_TIME,
	ERROR_STATE,
	ERROR_PHILO,
	NONE,
}				t_error;

void			error_msg(char *msg);
void			kill_process(t_state *state);
int				quit_philo(int code, t_time *time, t_state *state,
					t_philo *philo);

size_t			ft_strlen(char *str);
int				ft_atoi_philo(char *str, t_state *state);
bool			ft_is_digit(char c);
void			ft_putnbr(unsigned long nb, char *buff, size_t *i);
void			philo_msg(t_philo *philo, char *msg);

void			sleeping(t_philo *philo);
void			eating(t_philo *philo);
void			*check_status(void *param);
void			routine(t_philo *philo, t_state *state, pthread_t *status);
void			start_philosopher(t_philo *philo, pthread_t	*status);

#endif
