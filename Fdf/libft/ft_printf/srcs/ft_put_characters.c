/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_characters.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:06:23 by kytan             #+#    #+#             */
/*   Updated: 2024/05/19 14:06:23 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
		return (write(STDOUT_FILENO, "(null)", 6));
	return (write(STDOUT_FILENO, s, ft_strlen(s)));
}

int	ft_putchar(unsigned int c)
{
	return (write(STDOUT_FILENO, &c, 1));
}
