/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:13:09 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/08 19:50:34 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_init_tab(int tab[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_set_con_columns(char *str, t_conditions *conditions)
{
	int	i;
	int	offset;

	offset = 0;
	i = 0;
	while (i <= 6)
	{
		conditions->colup[i / 2] = str[i + offset] - 48;
		i += 2;
	}
	i = 0;
	offset = 8;
	while (i <= 6)
	{
		conditions->coldown[i / 2] = str[i + offset] - 48;
		i += 2;
	}
}

void	ft_set_con_rows(char *str, t_conditions *conditions)
{
	int	i;
	int	offset;

	i = 0;
	offset = 16;
	while (i <= 6)
	{
		conditions->rowleft[i / 2] = str[i + offset] - 48;
		i += 2;
	}
	i = 0;
	offset = 24;
	while (i <= 6)
	{
		conditions->rowright[i / 2] = str[i + offset] - 48;
		i += 2;
	}
}

void	ft_set_conditions(char *str, t_conditions *conditions)
{
	ft_set_con_columns(str, conditions);
	ft_set_con_rows(str, conditions);
}
