/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_waiter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:06:37 by kytan             #+#    #+#             */
/*   Updated: 2024/10/31 00:21:02 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_philo	*philo)
{
	t_simulation	*dinner;

	dinner = philo->dinner;
	pthread_mutex_lock(&philo->meal_lock);
	if ((get_curr_time() - philo->last_meal) >= philo->args[TIME_TO_DIE]
		&& !philo->eating)
	{
		pthread_mutex_unlock(&philo->meal_lock);
		print_msg(DIED, philo);
		pthread_mutex_lock(&dinner->death_lock);
		philo->dinner->state = DEAD;
		pthread_mutex_unlock(&dinner->death_lock);
		ft_usleep(1000);
		return (DEAD);
	}
	pthread_mutex_unlock(&philo->meal_lock);
	return (ALIVE);
}

static int	check_full(t_philo	*philos, long philos_full)
{
	if (philos->args[MEALS_LIMIT] == -1)
		return (HUNGRY);
	if (philos_full >= philos->args[NO_OF_PHILOS])
	{
		pthread_mutex_lock(&philos->dinner->death_lock);
		philos->dinner->state = DEAD;
		pthread_mutex_unlock(&philos->dinner->death_lock);
		return (FULL);
	}
	return (HUNGRY);
}

void	*waiter_routine(void *dinner_param)
{
	t_simulation	*dinner;
	t_philo			*philo;
	long			philos_full;

	philos_full = 0;
	dinner = (t_simulation *)dinner_param;
	philo = dinner->first;
	while (1)
	{
		if (check_death(philo) || check_full(philo, philos_full))
			break ;
		if (dinner->args[MEALS_LIMIT] != -1)
		{
			pthread_mutex_lock(&philo->meal_lock);
			if (philo->meals_eaten >= dinner->args[MEALS_LIMIT])
				philos_full++;
			pthread_mutex_unlock(&philo->meal_lock);
		}
		philo = philo->next;
	}
	return (dinner);
}
