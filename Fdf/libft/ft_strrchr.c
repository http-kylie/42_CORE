/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:32:14 by kytan             #+#    #+#             */
/*   Updated: 2024/03/05 17:29:13 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*occ;

	occ = 0;
	while (*s)
	{
		if (*(unsigned char *)s == (unsigned char)c)
			occ = (char *)s;
		s++;
	}
	if (*s == c)
		occ = (char *)s;
	return (occ);
}
