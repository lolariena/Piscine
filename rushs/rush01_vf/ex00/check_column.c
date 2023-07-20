/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_column.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:49:12 by nrea              #+#    #+#             */
/*   Updated: 2023/07/09 15:56:28 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_occ_cl(int **tab, int ln_index, int cl_index, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (i != ln_index && tab[i][cl_index] == tab[ln_index][cl_index])
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_col_ud(int **tab, int col, t_conditions conditions)
{
	int	i;
	int	biggest;
	int	nb_vis;

	i = 0;
	biggest = 0;
	nb_vis = 0;
	while (i < conditions.size)
	{
		if (tab[i][col] > biggest)
		{
			nb_vis++;
			biggest = tab[i][col];
		}
		i++;
	}
	if (conditions.colup[col] != nb_vis)
		return (0);
	return (1);
}

int	ft_check_col_du(int **tab, int col, t_conditions conditions)
{
	int	i;
	int	biggest;
	int	nb_vis;

	i = conditions.size - 1;
	biggest = 0;
	nb_vis = 0;
	while (i >= 0)
	{
		if (tab[i][col] > biggest)
		{
			nb_vis++;
			biggest = tab[i][col];
		}
		i--;
	}
	if (conditions.coldown[col] != nb_vis)
		return (0);
	return (1);
}

int	ft_check_col(int **tab, int col, t_conditions conditions)
{
	if (ft_check_col_ud(tab, col, conditions) == 0)
		return (0);
	if (ft_check_col_du(tab, col, conditions) == 0)
		return (0);
	return (1);
}
