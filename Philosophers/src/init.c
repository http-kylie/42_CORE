/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:16:39 by kytan             #+#    #+#             */
/*   Updated: 2024/10/31 08:42:52 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	init_curr_philo_params(t_philo *curr_philo, t_simulation *dinner,
	int i)
{
	curr_philo->id = i;
	curr_philo->args = dinner->args;
	curr_philo->eating = 0;
	curr_philo->meals_eaten = 0;
	curr_philo->dinner = dinner;
}

int	init_philos(t_simulation *dinner, t_philo *first)
{
	int			i;
	t_philo		*curr_philo;

	i = 0;
	curr_philo = first;
	while (++i <= dinner->args[NO_OF_PHILOS])
	{
		init_curr_philo_params(curr_philo, dinner, i);
		if (pthread_mutex_init(&curr_philo->fork, NULL))
			exit_error(dinner, MUTEX_INIT_FAILED);
		if (dinner->args[MEALS_LIMIT] != -1
			&& pthread_mutex_init(&curr_philo->meal_lock, NULL))
			exit_error(dinner, MUTEX_INIT_FAILED);
		if (i == dinner->args[NO_OF_PHILOS])
			break ;
		curr_philo->next = ft_calloc(1, sizeof(t_philo));
		if (!curr_philo->next)
			exit_error(dinner, MALLOC_ERROR);
		curr_philo->next->prev = curr_philo;
		curr_philo = curr_philo->next;
	}
	curr_philo->next = dinner->first;
	dinner->first->prev = curr_philo;
	dinner->last = curr_philo;
	return (SUCCESS);
}

int	init_simulation(t_simulation *dinner, int argc, char **argv)
{
	dinner->start_time = get_curr_time();
	dinner->args = parse_input(argc, argv);
	dinner->state = ALIVE;
	if (pthread_mutex_init(&dinner->death_lock, NULL))
		exit_error(dinner, MUTEX_INIT_FAILED);
	if (pthread_mutex_init(&dinner->msg_lock, NULL))
		exit_error(dinner, MUTEX_INIT_FAILED);
	dinner->first = ft_calloc(1, sizeof(t_philo));
	init_philos(dinner, dinner->first);
	return (SUCCESS);
}
