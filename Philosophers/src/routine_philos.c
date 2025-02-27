/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:33:07 by kytan             #+#    #+#             */
/*   Updated: 2024/10/31 08:59:01 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_think(t_philo *thread)
{
	print_msg(THINK, thread);
}

void	philo_sleep(t_philo *thread)
{
	print_msg(SLEEP, thread);
	ft_usleep(thread->args[TIME_TO_SLEEP]);
}

void	philo_eat(t_simulation *dinner, t_philo *thread)
{
	if (dinner->args[NO_OF_PHILOS] == 1)
	{
		ft_usleep(dinner->args[TIME_TO_EAT]);
		return ;
	}
	take_forks(thread);
	print_msg(EAT, thread);
	pthread_mutex_lock(&thread->meal_lock);
	thread->last_meal = get_curr_time();
	thread->eating = 1;
	thread->meals_eaten++;
	pthread_mutex_unlock(&thread->meal_lock);
	thread->eating = 0;
	ft_usleep(dinner->args[TIME_TO_EAT]);
	put_forks(thread);
}

static int	check_simulation(t_simulation *dinner)
{
	pthread_mutex_lock(&dinner->death_lock);
	if (dinner->state == DEAD)
	{
		pthread_mutex_unlock(&dinner->death_lock);
		return (END_SIMULATION);
	}
	pthread_mutex_unlock(&dinner->death_lock);
	return (CONTINUE_SIMULATION);
}

void	*philo_routine(void *func_arg)
{
	t_philo			*thread;
	t_simulation	*dinner;

	thread = (t_philo *)func_arg;
	dinner = (t_simulation *)thread->dinner;
	if (thread->id % 2 == 0)
		ft_usleep(500);
	while (check_simulation(dinner))
	{
		philo_eat(dinner, thread);
		philo_sleep(thread);
		philo_think(thread);
	}
	return (dinner);
}
