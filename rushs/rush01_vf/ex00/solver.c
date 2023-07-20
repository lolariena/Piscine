/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:00:17 by nrea              #+#    #+#             */
/*   Updated: 2023/07/09 16:18:39 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_occurences(int col, int line, int **grid, int size)
{
	if (!ft_check_occ_ln(grid[line], col, size))
		return (0);
	if (!ft_check_occ_cl(grid, line, col, size))
		return (0);
	return (1);
}

int	ft_solve(int col, int line, t_conditions cond, int **grid)
{
	int	i;

	if (col > cond.size - 1)
	{
		col = 0;
		line += 1;
	}
	if (line == cond.size)
		return (1);
	i = 0;
	while (++i <= cond.size)
	{
		grid[line][col] = i;
		if (!ft_check_occurences(col, line, grid, cond.size))
			continue ;
		if ((col == cond.size - 1) && !ft_check_line(grid[line], line, cond))
			continue ;
		if ((line == cond.size - 1) && !ft_check_col(grid, col, cond))
			continue ;
		if (ft_solve(col + 1, line, cond, grid))
			return (1);
	}
	grid[line][col] = 0;
	return (0);
}
