/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_t_state_constructor_destructor.        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:28:45 by gozsertt          #+#    #+#             */
/*   Updated: 2021/09/08 18:13:12 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_state	*malloc_state(int argc, char **argv)
{
	t_state	*state;

	state = (t_state *)malloc(sizeof(t_state));
	if (state == NULL)
	{
		error_msg("Error: malloc_state failed");
		state->error_state = true;
		return (state);
	}
	*state = create_state(argc, argv);
	return (state);
}

t_state	create_state(int argc, char **argv)
{
	t_state	state;

	memset(&state, 0, sizeof(t_state));
	if (argc == 5 || argc == 6)
	{
		parse_philo(argv[1], &state);
		parse_time_to_die(argv[2], &state);
		parse_time_to_eat(argv[3], &state);
		parse_time_to_sleep(argv[4], &state);
		if (argc == 6)
			parse_nb_time_to_eat(argv[5], &state);
		else
			state.nb_time_to_eat = -1;
		create_state_semaphore(&state);
		create_state_pid(&state);
		state.over = false;
	}
	else
	{
		error_msg("Error: Arguments");
		state.error_state = true;
	}
	return (state);
}

void	destroy_state(t_state state)
{
	free(state.pid);
	sem_close(get_state_write_semaphore_one(&state));
	sem_unlink("write_semaphore_one");
	sem_close(get_state_write_semaphore_two(&state));
	sem_unlink("write_semaphore_two");
	sem_close(get_state_write_semaphore_three(&state));
	sem_unlink("write_semaphore_three");
	sem_close(get_state_fork_semaphore(&state));
	sem_unlink("fork_semaphore_priority");
	sem_close(get_state_fork_semaphore(&state));
	sem_unlink("fork_semaphore");
	memset(&state, 0, sizeof(state));
}

void	free_state(t_state *state)
{
	destroy_state(*state);
	free(state);
}
