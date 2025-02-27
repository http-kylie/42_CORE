/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 03:53:45 by kytan             #+#    #+#             */
/*   Updated: 2024/10/30 23:53:57 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define SUCCESS 0
# define ERROR 1

# define ALIVE 0
# define DEAD 1

# define HUNGRY 0
# define FULL 1

# define END_SIMULATION 0
# define CONTINUE_SIMULATION 1

# define NO_OF_PHILOS 0
# define TIME_TO_DIE 1
# define TIME_TO_EAT 2
# define TIME_TO_SLEEP 3
# define MEALS_LIMIT 4

# define TIME "gettimeofday() failed :("
# define INVALID_INPUT "Input is invalid"
# define INIT_FAILED "Initialization of dinner simulation failed"
# define MUTEX_INIT_FAILED "Mutex init failed"
# define SIMULATION_FAILED "Simulation failed to Run"
# define MUTEX_DESTROY_ERROR "Destroy mutex failed"
# define MALLOC_ERROR "Memory allocation failed"
# define THREAD_CREATE_FAILED "Thread create failed"
# define THREAD_JOIN_FAILED "Thread join failed"

# define FORK "has taken a fork"
# define DIED "has died"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"

#endif