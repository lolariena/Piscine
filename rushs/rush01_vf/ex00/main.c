/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtixier <vtixier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:23:44 by vtixier           #+#    #+#             */
/*   Updated: 2023/07/09 17:24:27 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_check_num_range(char *str, int size)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 32 && !ft_isnum(str[i], size))
		{
			ft_error();
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_init_conditions(char *str, t_conditions *conditions)
{
	int	check;

	check = ft_check_arg(str);
	if (check < 12 || check > 36 || check % 4)
	{
		ft_error();
		return (0);
	}
	conditions->size = check / 4;
	if (!ft_check_num_range(str, conditions->size))
		return (0);
	ft_set_conditions(str, conditions);
	return (1);
}

int	main(int argc, char **argv)
{
	t_conditions	conditions;
	int				**grid;

	if (argc != 2)
	{
		ft_error();
		return (0);
	}
	if (!ft_init_conditions(argv[1], &conditions))
		return (0);
	grid = ft_init_tab(conditions.size);
	if (!grid)
	{
		ft_error();
		return (0);
	}
	if (ft_solve(0, 0, conditions, grid))
		ft_put_grid(grid, conditions.size);
	else
		ft_error();
	free(grid);
	return (0);
}
