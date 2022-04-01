/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 13:53:02 by jting             #+#    #+#             */
/*   Updated: 2022/02/17 11:58:52 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = malloc(nitems * size);
	if (!ptr)
		return (NULL);
	while (i < (nitems * size))
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)(ptr));
}	
