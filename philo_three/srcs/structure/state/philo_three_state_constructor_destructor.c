/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three_state_constructor_destructor.c         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gozsertt <gozsertt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 18:28:45 by gozsertt          #+#    #+#             */
/*   Updated: 2020/12/07 18:56:14 by gozsertt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_state	*malloc_state(int argc, char **argv)
{
	t_state *state;

	state = (t_state*)malloc(sizeof(t_state));
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
	t_state state;

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
		state.over = false;
	}
	else
	{
		error_msg("Error: Arguments\n");
		state.error_state = true;
	}
	return(state);
}

void	destroy_state(t_state state)
{
	sem_close(get_state_write_semaphore_one(&state));
	sem_unlink("write_semaphore_one");
	// free(state.write_semaphore_one);
	sem_close(get_state_write_semaphore_two(&state));
	sem_unlink("write_semaphore_two");
	// free(state.write_semaphore_two);
	sem_close(get_state_fork_semaphore(&state));
	sem_unlink("fork_semaphore_priority");
	sem_close(get_state_fork_semaphore(&state));
	sem_unlink("fork_semaphore");
	memset(&state, 0, sizeof(state));
}

void    free_state(t_state *state)
{
	destroy_state(*state);
	free(state);
}