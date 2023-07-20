/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:13:09 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/09 16:05:13 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	**ft_create_grid(int size)
{
	int	**tab;
	int	i;

	tab = malloc(sizeof(int *) * size);
	if (!tab)
		return (0);
	i = 0;
	while (i < size)
	{
		tab[i] = malloc(size * sizeof(int));
		if (!tab[i])
			return (0);
		i++;
	}
	return (tab);
}

int	**ft_init_tab(int size)
{
	int	i;
	int	j;
	int	**tab;

	tab = ft_create_grid(size);
	if (!tab)
		return (0);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			tab[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tab);
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
	offset = conditions->size * 2;
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
	offset = conditions->size * 4;
	while (i <= 6)
	{
		conditions->rowleft[i / 2] = str[i + offset] - 48;
		i += 2;
	}
	i = 0;
	offset = conditions->size * 6;
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
