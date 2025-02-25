/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kytan <kytan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 12:11:57 by kytan             #+#    #+#             */
/*   Updated: 2024/03/01 12:16:04 by kytan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*trash;

	if (!lst)
		return ;
	while (*lst)
	{
		trash = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(trash, del);
	}
}
