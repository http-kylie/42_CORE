/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:41:06 by kytan             #+#    #+#             */
/*   Updated: 2024/03/09 15:03:23 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*ret;

	if (!n || !size)
	{
		ret = malloc(0);
		return (ret);
	}
	if (n > INT_MAX / size)
		return (0);
	ret = malloc(size * n);
	if (!ret)
		return (0);
	ft_bzero(ret, size * n);
	return (ret);
}
