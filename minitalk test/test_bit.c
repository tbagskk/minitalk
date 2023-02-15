#include <stdio.h>

int main(void)
{
char *str = "01100001";
int i = 0;
char a = 0xFF;
int bit = 0;


while (str[i])
{
	
	if (str[i] == '1')
		a |= 128 >> bit;
	else a ^= 128 >> bit;
	if (++bit == 8)
	{
		printf("%c",a);
		bit = 0;
		a = 0;
	}
	i++;
}
}