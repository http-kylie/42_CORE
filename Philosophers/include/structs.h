/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 04:02:53 by kytan             #+#    #+#             */
/*   Updated: 2024/10/30 23:58:14 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef pthread_mutex_t		t_mutex;
typedef struct s_philo		t_philo;
typedef pthread_t			t_waiter;

typedef struct s_simulation
{
	long		start_time;
	int			state;
	long		*args;
	t_mutex		death_lock;
	t_mutex		msg_lock;
	t_philo		*first;
	t_philo		*last;
}	t_simulation;

typedef struct s_philo
{
	long						id;
	pthread_t					thread_id;
	long						*args;
	long						meals_eaten;
	long						eating;
	long						last_meal;
	t_mutex						fork;
	t_mutex						meal_lock;
	struct s_philo				*prev;
	struct s_philo				*next;
	t_simulation				*dinner;
}	t_philo;

#endif