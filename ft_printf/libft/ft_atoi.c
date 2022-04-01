/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 14:38:08 by jting             #+#    #+#             */
/*   Updated: 2022/04/01 11:28:19 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_space(const char *s)
{
	int	i;

	i = 0;
	while (s[i] == '\t' || s[i] == '\n' || s[i] == '\v' || \
			s[i] == '\f' || s[i] == '\r' || s[i] == ' ')
		i++;
	return (i);
}

int	ft_atoi(const char *s)
{
	int			i;
	int			sign;
	long int	result;

	sign = 1;
	if (!s)
		return (0);
	i = ft_space(s);
	if (s[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result = result + s[i] - '0';
		i++;
	}
	return (result * sign);
}
