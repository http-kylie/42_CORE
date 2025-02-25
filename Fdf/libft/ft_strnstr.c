/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 12:51:00 by kytan             #+#    #+#             */
/*   Updated: 2024/03/04 08:21:15 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (0);
	i = 0;
	n_len = ft_strlen(needle);
	while (haystack[i] && (i + n_len <= len))
	{
		if (!ft_strncmp(haystack + i, needle, n_len))
			return ((char *)haystack + i);
		++i;
	}
	return (0);
}
