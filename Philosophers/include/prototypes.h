/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 04:05:37 by kytan             #+#    #+#             */
/*   Updated: 2024/10/31 08:48:44 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

int		validate_input(int argc, char **argv);
long	*parse_input(int argc, char **argv);

int		init_simulation(t_simulation *dinner, int argc, char **argv);

int		init_philos(t_simulation *dinner, t_philo *first);

void	run_simulation(t_simulation *dinner);
void	create_waiter_thread(t_simulation *dinner, t_waiter *waiter);
void	create_philo_threads(t_simulation *dinner, t_philo *first);

void	*philo_routine(void *func_arg);

void	*waiter_routine(void *dinner);

void	exit_error(t_simulation *dinner, char *err_msg);
void	free_resources(t_simulation *dinner);
void	destroy_philos(t_simulation *dinner);

int		ft_non_digit(char **argv);
void	*ft_calloc(size_t n, size_t size);
void	ft_usleep(long usec);

long	get_curr_time(void);
void	put_forks(t_philo *thread);
void	take_forks(t_philo *thread);
void	print_msg(char *str, t_philo *philos);

#endif