int	ft_atoi(char *str)
{
	int	a;
	int	mult;
	int	nb;

	mult = 1;
	nb = 0;
	a = 0;
	while (str[a] == ' ' || (str[a] >= '\t' && str[a] <= '\r'))
		a++;
	if (str[a] == '-')
		mult = -1;
	if (str[a] == '+' || str[a] == '-')
		a++;
	if (str[a] < '0' || str[a] > '9')
		return (-1);
	while (str[++a - 1] >= '0' && str[a - 1] <= '9')
		nb = (nb * 10) + (str[a - 1] - '0');
	return (nb * mult);
}
