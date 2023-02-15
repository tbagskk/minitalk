/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmuller <dmuller@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:26:41 by dmuller           #+#    #+#             */
/*   Updated: 2023/01/25 10:42:31 by dmuller          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
//#include "ft_printf/libftprintf.h"

void	sendbits(int pid, char c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((c >> bit & 1) == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		bit++;
	}
}

int	ft_isdigit(int c)
{
	int	i;

	i = 0;
	if (c >= '0' && c <= '9')
		i = 1;
	return (i);
}

int	ft_atoi(const char *str)
{
	int	a;
	int	s;
	int	n;

	a = 0;
	s = 1;
	n = 0;
	while (str[a] == '\t' || str[a] == '\n' || str[a] == '\v'
		|| str[a] == '\f' || str[a] == '\r' || str[a] == ' ')
		a++;
	if (str[a] == '-')
		s = -1;
	if (str[a] == '-' || str[a] == '+')
		a++;
	while (ft_isdigit(str[a]) && str[a])
		n = (n * 10) + (str[a++] - '0');
	return (n * s);
}

int	main(int ac, char **av)
{
	int	pid;
	int	i;

	i = 0;
	if (ac != 3)
	{
		printf("Wrong amount of arguments\n");
		return (0);
	}
	pid = ft_atoi(av[1]);
	while (av[2][i])
		sendbits(pid, av[2][i++]);
}
