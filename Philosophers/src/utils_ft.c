/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 17:00:41 by kytan             #+#    #+#             */
/*   Updated: 2024/10/31 00:13:21 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_non_digit(char **argv)
{
	int		i;
	int		j;

	i = -1;
	while (argv[++i])
	{
		j = 0;
		while (argv[i][j] >= '0' && argv[i][j] <= '9')
		{
			j++;
		}
		if (argv[i][j] != '\0')
			return (1);
	}
	return (0);
}

void	*ft_calloc(size_t n, size_t size)
{
	void	*ptr;
	void	*ptr_cpy;
	int		haha;

	if (!n || !size)
		return (malloc(0));
	if (n > UINT_MAX / size)
		return (0);
	ptr = malloc(n * size);
	haha = n * size;
	ptr_cpy = ptr;
	if (ptr)
	{
		while (haha--)
			*((unsigned char *)ptr_cpy++) = 0;
	}
	return (ptr);
}

void	ft_usleep(long usec)
{
	long	start;
	long	diff;

	start = get_curr_time();
	while (1)
	{
		diff = usec - (get_curr_time() - start);
		if (diff <= 0)
			break ;
		if (diff > 10000)
			usleep(diff / 2);
		else
			usleep(500);
	}
}
