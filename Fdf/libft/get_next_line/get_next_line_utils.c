/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:05:57 by kytan             #+#    #+#             */
/*   Updated: 2024/05/19 16:05:57 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../libft.h"

char	*ft_freejoin(char *stash, char *buffer)
{
	char	*str;
	size_t	size;

	if (!stash || !buffer)
		return (0);
	size = ft_strlen(stash) + ft_strlen(buffer) + 1;
	str = malloc(size);
	if (!str)
		return (0);
	ft_strlcpy(str, stash, size);
	free(stash);
	ft_strlcpy(str + ft_strlen(str), buffer, size - ft_strlen(str));
	return (str);
}
/*void	*ft_calloc(size_t n, size_t size)
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
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	while (*src && i + 1 < size)
	{
		*dst++ = *src++;
		++i;
	}
	if (i < size)
		*dst = '\0';
	while (*src++)
		++i;
	return (i);
}
*/
/*
char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(s) + 1;
	dup = malloc(size);
	if (!dup)
		return (NULL);
	ft_strlcpy(dup, s, size);
	return (dup);
}

char	*ft_freejoin(char *stash, char *buffer)
{
	char	*str;
	size_t	size;

	if (!stash || !buffer)
		return (0);
	size = ft_strlen(stash) + ft_strlen(buffer) + 1;
	str = malloc(size);
	if (!str)
		return (0);
	ft_strlcpy(str, stash, size);
	free(stash);
	ft_strlcpy(str + ft_strlen(str), buffer, size - ft_strlen(str));
	return (str);
}
*/