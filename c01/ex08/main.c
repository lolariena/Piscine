#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size);

int		main(void)
{
	int c[5] = {65,-10,59,0,60};
	ft_sort_int_tab(c, 5);
	printf("Ordre croissant:? ");
	printf("%d, %d, %d, %d, %d", c[0], c[1], c[2], c[3], c[4]);
}
