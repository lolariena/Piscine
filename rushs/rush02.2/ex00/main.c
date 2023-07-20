#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(char *str);

int	main(int argc, char **argv)
{
	int number;

	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
	}
	else if (argc == 3)
	{
		number = ft_atoi(argv[2]);
	} 
	if (number >= 0)
	{
		printf("positive %d \n", number);
	}
	else
	{
		printf("negative %d \n", number);
	}
}
