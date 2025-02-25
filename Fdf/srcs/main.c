/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 18:36:34 by kytan             #+#    #+#             */
/*   Updated: 2024/06/16 18:36:34 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	char	*file;
	t_map	*map;

	if (ac != 2)
		exit_err(INVALID_ARGS_ERROR);
	file = av[1];
	map = init_map(file);
	begin_mlx(map);
	free_map_mem(map);
	return (SUCCESS);
}
