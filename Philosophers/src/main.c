/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:09:58 by kytan             #+#    #+#             */
/*   Updated: 2024/10/31 08:50:59 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_philo_threads(t_simulation *dinner, t_philo *first)
{
	t_philo			*current;

	current = first;
	dinner->start_time = get_curr_time();
	while (1)
	{
		current->last_meal = get_curr_time();
		if (pthread_create(&current->thread_id, NULL, philo_routine, current))
			exit_error(dinner, THREAD_CREATE_FAILED);
		current = current->next;
		if (current == dinner->first)
			break ;
	}
}

void	create_waiter_thread(t_simulation *dinner, t_waiter *waiter)
{
	if (pthread_create(waiter, NULL, waiter_routine, dinner) != 0)
		exit_error(dinner, THREAD_CREATE_FAILED);
}

void	join_all_threads(t_simulation *dinner, t_waiter *waiter)
{
	t_philo	*thread;

	thread = dinner->first;
	if (pthread_join(*waiter, NULL))
		exit_error(dinner, THREAD_JOIN_FAILED);
	while (1)
	{
		if (pthread_join(thread->thread_id, NULL))
			exit_error(dinner, THREAD_JOIN_FAILED);
		thread = thread->next;
		if (thread == dinner->first)
			break ;
	}
}

void	run_simulation(t_simulation *dinner)
{
	t_philo		*philos;
	t_waiter	waiter;

	philos = dinner->first;
	if (dinner->args[MEALS_LIMIT] == 0)
		exit_error(dinner, "Philos have nothing to eat");
	create_waiter_thread(dinner, &waiter);
	create_philo_threads(dinner, philos);
	join_all_threads(dinner, &waiter);
}

int	main(int argc, char **argv)
{
	t_simulation	*dinner;

	if (validate_input(argc, argv) != SUCCESS)
		exit_error(NULL, INVALID_INPUT);
	dinner = ft_calloc(1, sizeof(t_simulation));
	if (dinner == NULL)
		exit_error(dinner, MALLOC_ERROR);
	init_simulation(dinner, argc, argv + 1);
	run_simulation(dinner);
	free_resources(dinner);
}
