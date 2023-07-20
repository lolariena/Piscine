/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtixier <vtixier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:23:44 by vtixier           #+#    #+#             */
/*   Updated: 2023/07/09 16:19:00 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	int				check;
	t_conditions	conditions;
	int				**grid;

	if (argc != 2)
	{
		ft_error();
		return (0);
	}
	check = ft_check_arg(argv[1]);
	if (check < 12 || check > 36 || check % 4)
	{
write(1, "Pouet\n", 6);
		ft_error();
		return (0);
	}
	conditions.size = check / 4;
	
	int i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] != 32 && !ft_isnum(argv[1][i], conditions.size))
		{
write(1, "Tagada\n", 7);
			ft_error();
			return (0);
		}
		i++;
	}
	ft_set_conditions(argv[1], &conditions);
	grid = ft_init_tab(conditions.size);
	if (!grid)
	{
write(1, "gneu\n", 5);
		ft_error();
		return (0);
	}
	if (ft_solve(0, 0, conditions, grid))
		ft_put_grid(grid, conditions.size);
	else
	{
write(1, "Pepou\n", 6);
		ft_error();
		}
	free(grid);
	return (0);
}
