/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:36:29 by jting             #+#    #+#             */
/*   Updated: 2022/02/17 11:54:01 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	if (dstsize == 0)
		return (ft_strlen((char *)(src)));
	i = 0;
	while (dst[i] && i < dstsize)
		i++;
	j = 0;
	while (src[j] && (i + j) < (dstsize - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i + j < dstsize)
		dst[i + j] = '\0';
	j = 0;
	while (src[j])
		j++;
	return (i + j);
}	
