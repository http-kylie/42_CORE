/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 14:06:31 by kytan             #+#    #+#             */
/*   Updated: 2024/06/02 14:24:36 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned long int n, char specifier)
{
	int		len;

	len = 0;
	if (specifier != 'p')
		n = (unsigned)n;
	if (n > 15)
		len += ft_puthex(n / 16, specifier);
	if (specifier == 'X')
		len += ft_putchar("0123456789ABCDEF"[n % 16]);
	else
		len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_put_address(unsigned long long n)
{
	int	len;

	len = 0;
	if (n > 15)
		len += ft_put_address(n / 16);
	len += ft_putchar("0123456789abcdef"[n % 16]);
	return (len);
}

int	ft_putptr(void *n)
{
	int		len;

	len = 0;
	if (!n)
		return (ft_putstr(NIL));
	len += ft_putstr("0x");
	len += ft_put_address((unsigned long long)n);
	return (len);
}

int	ft_putdec(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		len += ft_putdec(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}

int	ft_putunint(unsigned int n)
{
	int	len;

	len = 0;
	if (n > 9)
		len += ft_putunint(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}
