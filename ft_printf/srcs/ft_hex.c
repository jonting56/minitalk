/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 10:19:32 by jting             #+#    #+#             */
/*   Updated: 2022/03/31 12:54:20 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_len(unsigned int n)
{
	int	i;

	i = 0;
	while (n != 0)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	ft_puthex(unsigned int n, const char spec)
{
	if (n >= 16)
	{
		ft_puthex(n / 16, spec);
		ft_puthex(n % 16, spec);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd((n + '0'), 1);
		else
		{	
			if (spec == 'x')
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (spec == 'X')
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}	
}

int	ft_printhex(unsigned int n, const char spec)
{
	if (n == 0)
		return (write (1, "0", 1));
	else
		ft_puthex(n, spec);
	return (hex_len(n));
}
