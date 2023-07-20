/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solve_c.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:49:12 by nrea              #+#    #+#             */
/*   Updated: 2023/07/08 17:26:04 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_col_ud(int tab[4][4], int col, t_conditions conditions)
{
	int	i;
	int	biggest;
	int	nb_vis;

	i = 0;
	biggest = 0;
	nb_vis = 0;
	while (i < 4)
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

int	ft_check_col_du(int tab[4][4], int col, t_conditions conditions)
{
	int	i;
	int	biggest;
	int	nb_vis;

	i = 3;
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

int	ft_check_col(int tab[4][4], int col, t_conditions conditions)
{
	if (ft_check_col_ud(tab, col, conditions) == 0)
		return (0);
	if (ft_check_col_du(tab, col, conditions) == 0)
		return (0);
	return (1);
}
/*
#include<stdio.h>

int main()
{

	t_conditions conditions;

	int tab[4][4];
	tab[0][0] = 1;
	tab[1][0] = 2;
	tab[2][0] = 3;
	tab[3][0] = 4;

	conditions.colup[0] = 4;
	conditions.coldown[0] = 1;

printf("%d\n", ft_check_col(tab,0,conditions));	
	return 0;
}*/
