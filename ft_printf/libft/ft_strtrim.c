/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:28:19 by jting             #+#    #+#             */
/*   Updated: 2022/02/23 16:25:23 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	get_start(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((char *)s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

int	get_end(char const *s1, char const *set)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen((char *)s1);
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i - 1]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*dst;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start >= end)
		return (ft_strdup(""));
	dst = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!dst)
		return (NULL);
	ft_strlcpy(dst, s1 + start, end - start + 1);
	return (dst);
}
