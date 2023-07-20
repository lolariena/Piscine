/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 15:15:41 by aibonade          #+#    #+#             */
/*   Updated: 2023/06/28 17:16:30 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_numbers(int a, int b, int c, int nb)
{
	if (nb > 0)
		write(1, ", ", 2);
	ft_putchar(a + 48);
	ft_putchar(b + 48);
	ft_putchar(c + 48);
}

void	ft_print_comb(void)
{
	int	h;
	int	t;
	int	u;
	int	cpt;

	h = 0;
	cpt = 0;
	while (h < 10)
	{
		t = h + 1;
		while (t < 10)
		{
			u = t + 1;
			while (u < 10)
			{
				ft_print_numbers(h, t, u, cpt);
				cpt++;
				u++;
			}
			t++;
		}
		h++;
	}
}
