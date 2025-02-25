/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:54:27 by kytan             #+#    #+#             */
/*   Updated: 2024/05/19 15:54:27 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "../libft.h"

char	*reset_stash(char *stash, int end)
{
	char	*tmp;

	if (end == -1)
	{
		free(stash);
		return (0);
	}
	tmp = stash;
	stash = ft_strdup(stash + end + 1);
	free(tmp);
	return (stash);
}

char	*extract_line(char *stash, int end)
{
	char	*line;

	if (end == -1)
		return (ft_strdup(stash));
	line = malloc(end + 2);
	if (line)
		ft_strlcpy(line, stash, end + 2);
	return (line);
}

char	*read_to_stash(int fd, char *stash, int *end)
{
	int		bytes_read;
	char	*buffer;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (0);
	while (ft_strchr_i(buffer, '\n') < 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0 || bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		stash = ft_freejoin(stash, buffer);
	}
	free(buffer);
	*end = ft_strchr_i(stash, '\n');
	if (bytes_read == -1 || !stash[0])
	{
		free(stash);
		stash = 0;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;
	int			end;

	if (fd < 0 || fd > MAX_FD || BUFFER_SIZE < 1)
		return (0);
	if (!stash[fd])
		stash[fd] = ft_calloc(1, 1);
	end = -1;
	stash[fd] = read_to_stash(fd, stash[fd], &end);
	if (!stash[fd])
		return (0);
	line = extract_line(stash[fd], end);
	stash[fd] = reset_stash(stash[fd], end);
	return (line);
}

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
}*/
// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	//int		fd3;
// 	fd1 = open("tests/test.txt", O_RDONLY);
// 	fd2 = open("tests/test2.txt", O_RDONLY);
// 	//fd3 = open("tests/test3.txt", O_RDONLY);
// 	i = 1;
// 	while (i < 2)
// 	{
// 		line = get_next_line(fd1);
// 		printf("line [%02d]: .%s.\n", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		printf("line [%02d]: .%s.\n", i, line);
// 		free(line);
// 		//line = get_next_line(fd3);
// 		//printf("line [%02d]: %s", i, line);
// 		//free(line);
// 		i++;
// 	}
// 	close(fd1);
// 	close(fd2);
// 	//close(fd3);
// 	return (0);
// }
