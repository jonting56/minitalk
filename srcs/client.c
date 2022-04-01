/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jting <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 12:09:00 by jting             #+#    #+#             */
/*   Updated: 2022/04/01 13:53:48 by jting            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

int	mini_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	sign = 1;
	if (!str)
		return (0);
	i = 0;
	result = 0;
	if (str[i] == '-')
	{	
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	send(unsigned char c, int t)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(t, SIGUSR2);
		else
			kill(t, SIGUSR1);
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;

	if (argc != 3)
	{
		write(1, "Incorrect input", 15);
		return (0);
	}
	pid = mini_atoi(argv[1]);
	i = 0;
	while (argv[2][i])
	{
		send(argv[2][i], pid);
		i++;
	}
	send(argv[2][i], pid);
}
