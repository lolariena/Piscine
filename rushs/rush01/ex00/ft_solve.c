/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 15:11:46 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/08 18:30:50 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_occ_ln(int tab[4], int index)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		if (j != index && tab[j] == tab[index])
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_occ_cl(int tab[4][4], int ln_index, int cl_index)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != ln_index && tab[i][cl_index] == tab[ln_index][cl_index])
			return (0);
		i++;
	}
	return (1);
}
/*
#include <stdio.h>
int	main()
{
	int tab[4][4];
	int	i;
	
	tab[0][0] = 1;
	tab[0][1] = 2;
	tab[0][2] = 4;
	tab[0][3] = 3;
	tab[1][0] = 1;
	tab[1][1] = 2;
	tab[1][2] = 3;
	tab[1][3] = 4;
	tab[2][0] = 1;
	tab[2][1] = 2;
	tab[2][2] = 2;
	tab[2][3] = 3;
	tab[3][0] = 4;
	tab[3][1] = 3;
	tab[3][2] = 1;
	tab[3][3] = 2;
	i = 0;
	while (i < 4)
	{
		printf("tab[%d] pour l'index %d donne %d\n", i, i, ft_check_occ_ln(tab[i], i));
		printf("tab[%d] pour l'index %d et %d donne %d\n\n", i, i, i, ft_check_occ_cl(tab, i, i));
		i++;
	}
	return (0);
}*/
