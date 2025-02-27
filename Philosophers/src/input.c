/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 04:21:16 by kytan             #+#    #+#             */
/*   Updated: 2024/10/31 09:16:06 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	*parse_input(int argc, char **argv)
{
	long	*input_array;
	int		i;

	i = -1;
	input_array = ft_calloc(argc, sizeof(long));
	if (!input_array)
		return (0);
	while (argv[++i])
		input_array[i] = atol(argv[i]);
	input_array[i] = -1;
	input_array[TIME_TO_DIE] *= 1000;
	input_array[TIME_TO_EAT] *= 1000;
	input_array[TIME_TO_SLEEP] *= 1000;
	return (input_array);
}

int	validate_input(int argc, char **argv)
{
	long		*args;

	if (argc != 5 && argc != 6)
		return (ERROR);
	if (ft_non_digit(argv + 1))
		exit_error(NULL, INVALID_INPUT);
	args = parse_input(argc, argv + 1);
	if (!args)
		return (ERROR);
	if (args[NO_OF_PHILOS] < 1)
		exit_error(NULL, "Enter at least ONE philo");
	if (args[TIME_TO_DIE] - args[TIME_TO_EAT] < args[TIME_TO_SLEEP])
		exit_error(NULL, "time_to_die should be more than or equal to \
				the sum of time_to_eat and time_to_sleep");
	free(args);
	return (SUCCESS);
}
