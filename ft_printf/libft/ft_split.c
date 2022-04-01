/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 13:45:58 by jting             #+#    #+#             */
/*   Updated: 2022/02/23 16:00:13 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_wordcount(char const *s, char c)
{
	unsigned int	i;
	unsigned int	words;

	i = 0;
	words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != '\0')
			words++;
		while (s[i] != c && s[i] != '\0')
		i++;
	}
	return (words);
}

static	unsigned int	ft_len(char const *s, char c)
{
	size_t			i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char				**dst;
	unsigned int		i;
	unsigned int		start;

	dst = (char **)malloc(sizeof(*dst) * (ft_wordcount(s, c) + 1));
	if (!dst || !s)
		return (NULL);
	i = 0;
	start = 0;
	while (i < ft_wordcount((char *)s, c))
	{
		while (s[start] == c)
			start++;
		dst[i] = ft_substr(s, start, ft_len(&s[start], c));
		start += ft_len(&s[start], c);
		i++;
	}
	dst[i] = 0;
	return (dst);
}
