/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 11:36:46 by aibonade          #+#    #+#             */
/*   Updated: 2023/06/29 12:40:33 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_test_neg(int nb)
{
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	return (nb);
}

void	ft_printnbr(int nb)
{
	if (nb != 0)
	{
		ft_printnbr(nb / 10);
		ft_putchar(nb % 10 + 48);
	}
}

void	ft_putnbr(int nb)
{
	if (nb != 0)
	{
		if (nb == -2147483648)
			write(1, "-2147483648", 11);
		else
		{
			nb = ft_test_neg(nb);
			ft_printnbr(nb);
		}
	}
	else
		ft_putchar('0');
}
