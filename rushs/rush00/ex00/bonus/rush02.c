/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glions <glions@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 11:55:13 by glions            #+#    #+#             */
/*   Updated: 2023/07/01 11:55:55 by glions           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_ln(int x, char d, char m, char f)
{
	int	i;

	i = 0;
	while (i < x)
	{
		if (i == 0)
			ft_putchar(d);
		else if (i == x - 1)
			ft_putchar(f);
		else
			ft_putchar(m);
		i++;
	}
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	if (x > 0 && y > 0)
	{
		i = 0;
		while (i < y)
		{
			if (i == 0)
				ft_print_ln(x, 'A', 'B', 'A');
			else if (i == y - 1)
				ft_print_ln(x, 'C', 'B', 'C');
			else
				ft_print_ln(x, 'B', ' ', 'B');
			i++;
		}
	}
}
