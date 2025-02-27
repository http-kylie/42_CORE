/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:40:17 by kytan             #+#    #+#             */
/*   Updated: 2024/10/31 08:46:57 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_curr_time(void)
{
	struct timeval	current_time;

	if (gettimeofday(&current_time, NULL) == -1)
		exit_error(NULL, TIME);
	return ((current_time.tv_sec * 1000000) + current_time.tv_usec);
}

void	print_msg(char *str, t_philo *philos)
{
	long			time;
	t_simulation	*dinner;

	dinner = philos->dinner;
	pthread_mutex_lock(&dinner->msg_lock);
	time = (get_curr_time() - dinner->start_time) / 1000;
	pthread_mutex_lock(&dinner->death_lock);
	if (dinner->state == ALIVE)
		printf("%ld %ld %s\n", time, philos->id, str);
	pthread_mutex_unlock(&dinner->death_lock);
	pthread_mutex_unlock(&dinner->msg_lock);
}

void	put_forks(t_philo *thread)
{
	pthread_mutex_unlock(&thread->fork);
	if (thread->args[NO_OF_PHILOS] == 1)
		return ;
	pthread_mutex_unlock(&thread->next->fork);
}

void	take_forks(t_philo *thread)
{
	pthread_mutex_lock(&thread->fork);
	print_msg(FORK, thread);
	if (thread->args[NO_OF_PHILOS] == 1)
		return ;
	pthread_mutex_lock(&thread->next->fork);
	print_msg(FORK, thread);
}
