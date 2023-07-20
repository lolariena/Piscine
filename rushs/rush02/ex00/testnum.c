#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	fonction(void)
{
	int	a;
	int	b;
	int	tab[10];
	int	nb;
	int	tmp;

	a = 10;
	b = 0;
	nb = 12;
	tmp = 0;
	while (nb != 0)
	{
		if (b == 3)
		{
			tab[b] = 1000;
			printf("%d \n", tab[b]);
		}
		if (b == 6)
		{
			tab[b] = 1000000;
			printf("%d \n", tab[b]);
		}
		if (b == 9)
		{
			tab[b] = 1000000000;
			printf("%d \n", tab[b]);
		}
		if (nb % a > 100)
		{
			tab[b] = 100;
			printf("%d \n", tab[b]);
			tab[b] = nb % a / 100;
			printf("%d \n", tab[b]);
			nb /= 1000;
			a /= 1000;
		}
		else
		{
			tab[b] = nb % a;
			printf("%d \n", tab[b]);
		}
		nb = (nb / a) * a;
		a = a * 10;
		b++;
	}
}

int	main(void)
{
	fonction();
}
