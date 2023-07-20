/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtixier <vtixier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:23:44 by vtixier           #+#    #+#             */
/*   Updated: 2023/07/08 19:29:03 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	main(int argc, char **argv)
{
	int				check;
	t_conditions	conditions;
	int				grid[4][4];

	if (argc != 2)
	{
		ft_error();
		return (0);
	}
	check = ft_check_arg(argv[1]);
	if (check != 16)
	{
		ft_error();
		return (0);
	}
	ft_set_conditions(argv[1], &conditions);
	ft_init_tab(grid);
	if (ft_solve(0, 0, conditions, grid))
		ft_put_grid(grid);
	else
		ft_error();
	return (0);
}
