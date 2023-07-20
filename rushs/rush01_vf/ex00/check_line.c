/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:39:50 by nrea              #+#    #+#             */
/*   Updated: 2023/07/09 15:57:40 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_occ_ln(int *tab, int index, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (j != index && tab[j] == tab[index])
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_line_lr(int *tab, int line, t_conditions conditions)
{
	int	i;
	int	nb_vis;
	int	biggest;

	i = 0;
	nb_vis = 0;
	biggest = 0;
	while (i < conditions.size)
	{
		if (tab[i] > biggest)
		{
			nb_vis++;
			biggest = tab[i];
		}
		i++;
	}
	if (conditions.rowleft[line] != nb_vis)
		return (0);
	return (1);
}

int	ft_check_line_rl(int *tab, int line, t_conditions conditions)
{
	int	i;
	int	nb_vis;
	int	biggest;

	i = conditions.size - 1;
	nb_vis = 0;
	biggest = 0;
	while (i >= 0)
	{
		if (tab[i] > biggest)
		{
			nb_vis++;
			biggest = tab[i];
		}
		i--;
	}
	if (conditions.rowright[line] != nb_vis)
		return (0);
	return (1);
}

int	ft_check_line(int *tab, int line, t_conditions conditions)
{
	if (!ft_check_line_lr(tab, line, conditions))
		return (0);
	if (!ft_check_line_rl(tab, line, conditions))
		return (0);
	return (1);
}
