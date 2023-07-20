/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 17:28:08 by aibonade          #+#    #+#             */
/*   Updated: 2023/06/29 11:29:35 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(int a, int b, int c, int d)
{
	ft_putchar(a + 48);
	ft_putchar(b + 48);
	write(1, " ", 1);
	ft_putchar(c + 48);
	ft_putchar(d + 48);
}

int	ft_print_comma(int cpt)
{
	if (cpt > 0)
		write(1, ", ", 2);
	return (cpt + 1);
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;
	int	c;
	int	d;
	int	cpt;

	a = -1;
	cpt = 0;
	while (++a < 10)
	{
		b = -1;
		while (++b < 10)
		{
			c = a - 1;
			while (++c < 10)
			{
				d = b;
				while (++d < 10)
				{
					cpt = ft_print_comma(cpt);
					ft_print_numbers(a, b, c, d);
				}
			}
		}
	}
}
