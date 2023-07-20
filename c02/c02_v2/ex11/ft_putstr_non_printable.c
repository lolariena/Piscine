/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 15:30:12 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/02 22:26:53 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puthexa(int c)
{
	char	*hexa;

	hexa = "0123456789abcdef";
	if (c < 16)
		write(1, &hexa[c], 1);
	else
	{
		ft_puthexa(c / 16);
		write(1, &hexa[c % 16], 1);
	}
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 31 && str[i] < 127)
			write(1, &str[i], 1);
		else
		{
			write(1, "\\", 1);
			if (str[i] < 16)
				write(1, "0", 1);
			ft_puthexa(str[i]);
		}
		i++;
	}
}
