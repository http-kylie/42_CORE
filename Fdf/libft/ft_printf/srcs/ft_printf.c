/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:42:31 by kytan             #+#    #+#             */
/*   Updated: 2024/03/15 07:42:31 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_formats(char c, va_list inputs)
{
	int	printed;

	printed = 0;
	if (c == '%')
		printed += ft_putchar(c);
	else if (c == 'c')
		printed += ft_putchar(va_arg(inputs, unsigned int));
	else if (c == 's')
		printed += ft_putstr(va_arg(inputs, char *));
	else if (c == 'p')
		printed += ft_putptr(va_arg(inputs, void *));
	else if (c == 'i' || c == 'd')
		printed += ft_putdec(va_arg(inputs, int));
	else if (c == 'u')
		printed += ft_putunint(va_arg(inputs, unsigned int));
	else if (c == 'x' || c == 'X')
		printed += ft_puthex(va_arg(inputs, unsigned), c);
	return (printed);
}

int	ft_printf(const char *format, ...)
{
	va_list			inputs;
	int				printed;

	printed = 0;
	va_start(inputs, format);
	while (*format)
	{
		if (*format == '%' && ++format)
			printed += ft_formats(*format++, inputs);
		else
			printed += ft_putchar(*format++);
	}
	va_end(inputs);
	return (printed);
}
/*
#include <stdio.h>
int main()
{
	void			*p = 0;
	//unsigned int	n = 18446;

	int ret1 = ft_printf("mine: [%p]\n", p);
	int ret2 = printf("real: [%p]\n", p);
	printf("\nmine: %i || real: %i\n", ret1, ret2);
}
*/