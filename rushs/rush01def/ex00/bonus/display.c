/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtixier <vtixier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:06:02 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/09 15:59:03 by aibonade         ###   ########.fr       */
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

void	ft_put_grid(int **grid, int size)
{
	int	row;
	int	col;

	row = 0;
	while (row < size)
	{
		col = 0;
		while (col < size)
		{
			ft_putchar(grid[row][col] + 48);
			if (col != size - 1)
				ft_putchar(' ');
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}
