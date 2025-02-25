/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 09:00:58 by kytan             #+#    #+#             */
/*   Updated: 2024/03/04 13:50:40 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s, const char *c, size_t n)
{
	unsigned char	*a;
	unsigned char	*b;

	a = (unsigned char *)s;
	b = (unsigned char *)c;
	if (n == 0)
		return (0);
	while (*a == *b && *a && --n)
	{
		++a;
		++b;
	}
	return (*a - *b);
}
