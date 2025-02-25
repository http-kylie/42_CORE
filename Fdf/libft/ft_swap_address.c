/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_address.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 08:50:20 by kytan             #+#    #+#             */
/*   Updated: 2024/06/02 14:21:24 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap_address(char **a, char **b)
{
	char	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
// swaps the address of two strings

int main() {
    char *str1 = "Hello";
    char *str2 = "World";

    printf("Before swapping:\n");
    printf("str1: %s, str2: %s\n", str1, str2);

    swapStrings(&str1, &str2);

    printf("After swapping:\n");
    printf("str1: %s, str2: %s\n", str1, str2);

    return 0;
}
*/
