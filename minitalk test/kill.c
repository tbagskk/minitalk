#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

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
int main(int ac, char **av)
{
	int pid = 45266;
	
	sendbits(pid, 'a');

	
	
	
	
}

