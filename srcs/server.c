/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:30:52 by jting             #+#    #+#             */
/*   Updated: 2022/04/01 13:50:16 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

t_data	g_bits;

void	reset_data(void)
{
	g_bits.i = 0;
	g_bits.c = 0;
}

void	handler(int sig)
{
	if (sig == SIGUSR2)
		sig = 1;
	else
		sig = 0;
	g_bits.c = g_bits.c << 1 | sig;
	g_bits.i++;
	if (g_bits.i == 8)
	{
		if (g_bits.i == '\0')
			write(1, "\n", 1);
		else
			write(1, &g_bits.c, 1);
		reset_data();
	}
}	

int	main(void)
{
	ft_printf("PID is %d\n", getpid());
	reset_data();
	while (1)
	{
		signal(SIGUSR1, &handler);
		signal(SIGUSR2, &handler);
		pause();
	}
	return (0);
}
