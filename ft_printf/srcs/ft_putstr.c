/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 11:54:48 by jting             #+#    #+#             */
/*   Updated: 2022/03/31 12:55:19 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

int	ft_printstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	num_len(int n)
{
	int			i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
	{
		n *= -1;
		i = 1;
	}
	while (n)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	char	*num;
	int		len;

	num = ft_itoa(n);
	len = ft_printstr(num);
	free(num);
	return (len);
}
