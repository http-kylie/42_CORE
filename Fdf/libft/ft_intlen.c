/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:39:58 by kytan             #+#    #+#             */
/*   Updated: 2024/04/05 08:39:58 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nb)
{
	if (nb / 10 == 0)
		return (1);
	return (1 + ft_intlen(nb / 10));
}
/*
#include <stdio.h>
int	main()
{
	int	nb = 0;

	printf("NUMBER %i\n", nb);
	printf("%i digits counted\n", ft_intlen(nb));
}
*/