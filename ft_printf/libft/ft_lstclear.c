/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:49:12 by jting             #+#    #+#             */
/*   Updated: 2022/02/24 11:06:30 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*count;

	count = *lst;
	if (lst && del)
	{	
		while (*lst)
		{
			count = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = count;
		}
	}
}
