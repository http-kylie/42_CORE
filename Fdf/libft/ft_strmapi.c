/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:39:04 by kytan             #+#    #+#             */
/*   Updated: 2024/03/01 12:39:04 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dup;
	unsigned char	i;

	if (!s || !f)
		return (0);
	dup = ft_strdup((char *)s);
	if (!dup)
		return (0);
	i = -1;
	while (dup[++i])
		dup[i] = f(i, dup[i]);
	return (dup);
}
