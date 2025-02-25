/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:06:12 by kytan             #+#    #+#             */
/*   Updated: 2024/05/19 16:06:12 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# define MAX_FD 1024

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*ft_freejoin(char *stash, char *buffer);
char	*read_to_stash(int fd, char *stash, int *end);
char	*extract_line(char *stash, int end);
char	*reset_stash(char *stash, int end);
char	*get_next_line(int fd);

/*
size_t	ft_strlen(const char *s);
int		ft_strchr_i(char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *s);
void	*ft_calloc(size_t n, size_t size);
*/

#endif