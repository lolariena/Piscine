/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:28:08 by aibonade          #+#    #+#             */
/*   Updated: 2023/06/30 12:09:41 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(int a, int b)
{
	ft_putchar(a / 10 + 48);
	ft_putchar(a % 10 + 48);
	write(1, " ", 1);
	ft_putchar(b / 10 + 48);
	ft_putchar(b % 10 + 48);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	cpt;

	a = 0;
	cpt = 0;
	while (a < 100)
	{
		b = a + 1;
		while (b < 100)
		{
			if (cpt > 0)
				write(1, ", ", 2);
			ft_print_numbers(a, b);
			cpt++;
			b++;
		}
		a++;
	}
}
