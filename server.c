/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcherqui <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 17:43:29 by gcherqui          #+#    #+#             */
/*   Updated: 2023/02/15 17:43:32 by gcherqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	display_function(int signal)
{	
	static int		bit = 0;
	static char		c = 0;

	if (signal == SIGUSR1)
		c += (0 << bit);
	if (signal == SIGUSR2)
		c += (1 << bit);
	if (++bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sasa;
	int					the_pid;

	(void)av;
	the_pid = getpid();
	sasa.sa_handler = &display_function;
	sasa.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sasa, 0);
	sigaction(SIGUSR2, &sasa, 0);
	ft_putnbr(the_pid);
	write(1, "\n", 1);
	while (1)
		continue ;
	return (0);
}
