/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 19:55:17 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/05 12:48:25 by aibonade         ###   ########.fr       */
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

void	ft_printnbr(int nb, char *base, int len)
{
	if (nb != 0)
	{
		if (nb == -2147483648)
		{
			write(1, "-", 1);
			ft_printnbr(2147483648 / len, base, len);
			ft_putchar(base[2147483648 % len]);
		}
		else
		{
			ft_printnbr(nb / len, base, len);
			ft_putchar(base[nb % len]);
		}
	}
}

int	ft_baseverif(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	ln_base;

	if (ft_baseverif(base))
	{
		ln_base = 0;
		while (base[ln_base])
			ln_base++;
		if (nbr != 0)
		{
			if (nbr == -2147483648)
				ft_printnbr(nbr, base, ln_base);
			else
			{
				nbr = ft_test_neg(nbr);
				ft_printnbr(nbr, base, ln_base);
			}
		}
		else
			ft_putchar(base[0]);
	}
}
