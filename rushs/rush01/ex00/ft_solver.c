/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 18:00:17 by nrea              #+#    #+#             */
/*   Updated: 2023/07/08 19:31:28 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_occurences(int col, int line, int grid[4][4])
{
	if (!ft_check_occ_ln(grid[line], col))
		return (0);
	if (!ft_check_occ_cl(grid, line, col))
		return (0);
	return (1);
}

int	ft_solve(int col, int line, t_conditions cond, int grid[4][4])
{
	int	i;

	if (col > 3)
	{
		col = 0;
		line += 1;
	}
	if (line == 4)
		return (1);
	i = 0;
	while (++i < 5)
	{
		grid[line][col] = i;
		if (!ft_check_occurences(col, line, grid))
			continue ;
		if (col == 3 && !ft_check_line(grid[line], line, cond))
			continue ;
		if (line == 3 && !ft_check_col(grid, col, cond))
			continue ;
		if (ft_solve(col + 1, line, cond, grid))
			return (1);
	}
	grid[line][col] = 0;
	return (0);
}
