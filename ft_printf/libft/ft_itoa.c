/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:11:18 by jting             #+#    #+#             */
/*   Updated: 2022/03/17 14:53:32 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	numlen(int n)
{
	int			i;
	long int	long_n;

	if (n == 0)
		return (1);
	i = 0;
	long_n = n;
	if (long_n < 0)
	{
		long_n *= -1;
		i = 1;
	}
	while (long_n)
	{
		i++;
		long_n /= 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*result;
	int			len;
	int long	long_n;
	int			i;

	len = numlen(n);
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	if (n == 0)
		result[0] = '0';
	long_n = n;
	if (long_n < 0)
		result[0] = '-';
	if (long_n < 0)
		long_n = long_n * -1;
	i = 0;
	while (long_n)
	{
		result[len - i - 1] = '0' + (long_n % 10);
		long_n /= 10;
		i++;
	}
	result[len] = '\0';
	return (result);
}
