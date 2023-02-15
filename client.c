/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:43:21 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/15 17:44:30 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void	sendbits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit & 1) == 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		bit++;
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		while (av[2][i])
			sendbits(pid, av[2][i++]);
	}
	else
		write(1, "not yet\n", 7);
	return (0);
}
