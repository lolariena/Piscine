/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtixier <vtixier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:06:02 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/08 15:24:34 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_put_grid(int grid[4][4])
{
	int	row;
	int	col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			ft_putchar(grid[row][col] + 48);
			if (col != 3)
				ft_putchar(' ');
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
