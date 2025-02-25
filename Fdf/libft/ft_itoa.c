/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 22:43:54 by kytan             #+#    #+#             */
/*   Updated: 2024/03/04 15:16:28 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	itoa_filler(char **ptr, int n)
{
	if (n == 0)
		return ;
	else
	{
		itoa_filler(ptr, (n / 10));
		**ptr = '0' + (n % 10);
		(*ptr)++;
	}
}

static int	count_digits(int n)
{
	int	digits;

	digits = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		digits++;
	while (n)
	{
		digits++;
		n /= 10;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	char	*str_n;
	char	*tmp_ptr;

	str_n = malloc(count_digits(n) + 1);
	if (!str_n)
		return (NULL);
	tmp_ptr = str_n;
	if (n == -2147483648)
	{
		ft_strlcpy(str_n, "-2147483648", 12);
		return (str_n);
	}
	if (n == 0)
		*tmp_ptr++ = '0';
	if (n < 0)
	{
		*tmp_ptr++ = '-';
		n *= -1;
	}
	itoa_filler(&tmp_ptr, n);
	*tmp_ptr = '\0';
	return (str_n);
}
