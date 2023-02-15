#include <signal.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


void caca_function(int signal)
{
            static int  bit;
                static int  c;

                    if(signal == SIGUSR1)
                                    c = c | (1 << bit);
                        if(++bit == 8)
                                    {
                                                    printf("%c",c);
                                                            bit = 0;
                                                                    c = 0;
                                                                        }
}

int main(void)
{
        struct sigaction caca;
        int pidd;

        pidd = getpid();

       // printf("%d", pidd);

        caca.sa_handler = &caca_function;
        caca.sa_flags = SA_RESTART;

        printf("%d",pidd);
         while(1)
            {
               //printf("%d",pidd);
                 sigaction(SIGUSR1, &caca, 0);
                sigaction(SIGUSR2, &caca, 0);
                usleep(10000);
                printf("%d",pidd);

            }
        return 0;
}