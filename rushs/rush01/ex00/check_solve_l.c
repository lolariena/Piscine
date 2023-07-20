/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_solve_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrea <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 16:39:50 by nrea              #+#    #+#             */
/*   Updated: 2023/07/08 17:33:00 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_line_lr(int tab[4], int line, t_conditions conditions)
{
	int	i;
	int	nb_vis;
	int	biggest;

	i = 0;
	nb_vis = 0;
	biggest = 0;
	while (i < 4)
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

int	ft_check_line_rl(int tab[4], int line, t_conditions conditions)
{
	int	i;
	int	nb_vis;
	int	biggest;

	i = 3;
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

int	ft_check_line(int tab[4], int line, t_conditions conditions)
{
	if (!ft_check_line_lr(tab, line, conditions))
		return (0);
	if (!ft_check_line_rl(tab, line, conditions))
		return (0);
	return (1);
}
/*
#include<stdio.h>

int main()
{

	t_conditions conditions;

	int tab[4];
	tab[0] = 2;
	tab[1] = 3;
	tab[2] = 4;
	tab[3] = 1;

	conditions.rowright[0] = 2;
	conditions.rowleft[0] = 3;

printf("%d\n", ft_check_line(tab,0,conditions));	
	return 0;
}*/
