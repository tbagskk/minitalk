#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i++])
		ft_putchar(str[i]);
}

void ft_putnbr(int nb)
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

void display_function(int signal)
{
    static int  bit = 0;
    static int  c = 0xFF;

    if(signal == SIGUSR1)
	{
		 c |= 128 >> bit;
		 write(1, "1", 1);
	}
	else 
	{
		c ^= 128 >> bit;
		write(1, "0", 1);
	}
    if(++bit == 8)
     {
		write(1, &c, 1);
        bit = 0;
        c = 0xFF;
    }
}

void test_function(int sig)
{
	write(1,"caca",4);
}


int main(int ac, char **av)
{
        struct sigaction sasa;
        int the_pid;

		(void)av;
        the_pid = getpid();
        sasa.sa_handler = &display_function;
        sasa.sa_flags = SA_RESTART;
		sigaction(SIGUSR1, &sasa, 0);
        sigaction(SIGUSR2, &sasa, 0);

        ft_putnbr(the_pid);
		write(1, "\n", 1);

         while(1)
		 	continue;
        return 0;
}





