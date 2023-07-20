void	ft_putstr_non_printable(char *str);

int		main(void)
{
	char	*str;

	str = "B\non jour\a";
	ft_putstr_non_printable(str);
	return 0;
}

