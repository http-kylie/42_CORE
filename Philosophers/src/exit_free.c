/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 08:30:48 by kytan             #+#    #+#             */
/*   Updated: 2024/10/31 08:33:57 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_philos(t_simulation *dinner)
{
	t_philo	*current;
	t_philo	*next;

	if (!dinner->first)
		return ;
	current = dinner->first;
	while (current != dinner->last)
	{
		next = current->next;
		if (pthread_mutex_destroy(&current->fork))
			exit_error(dinner, MUTEX_DESTROY_ERROR);
		if (pthread_mutex_destroy(&current->meal_lock))
			exit_error(dinner, MUTEX_DESTROY_ERROR);
		free(current);
		current = next;
	}
	if (pthread_mutex_destroy(&current->fork))
		exit_error(dinner, MUTEX_DESTROY_ERROR);
	if (pthread_mutex_destroy(&current->meal_lock))
		exit_error(dinner, MUTEX_DESTROY_ERROR);
	free(current);
	dinner->first = NULL;
	dinner->last = NULL;
}

void	free_resources(t_simulation *dinner)
{
	if (pthread_mutex_destroy(&dinner->death_lock))
		exit_error(NULL, MUTEX_DESTROY_ERROR);
	if (pthread_mutex_destroy(&dinner->msg_lock))
		exit_error(NULL, MUTEX_DESTROY_ERROR);
	destroy_philos(dinner);
	free(dinner->args);
	free(dinner);
}

void	exit_error(t_simulation *dinner, char *err_msg)
{
	if (dinner)
		free_resources(dinner);
	if (!err_msg)
		exit(SUCCESS);
	printf("%s\n", err_msg);
	exit(1);
}
