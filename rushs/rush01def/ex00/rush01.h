/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtixier <vtixier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:01:53 by vtixier           #+#    #+#             */
/*   Updated: 2023/07/08 19:28:11 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <unistd.h>

typedef struct s_conditions
{
	int	colup[4];
	int	coldown[4];
	int	rowleft[4];
	int	rowright[4];
}	t_conditions;

void		ft_error(void);
int			ft_check_arg(char *str);
void		ft_set_conditions(char *str, t_conditions *conditions);
void		ft_init_tab(int tab[4][4]);
void		ft_put_grid(int grid[4][4]);
int			ft_check_line(int tab[4], int line, t_conditions conditions);
int			ft_check_col(int tab[4][4], int col, t_conditions conditions);
int			ft_check_occ_ln(int tab[4], int index);
int			ft_check_occ_cl(int tab[4][4], int ln_index, int cl_index);
int			ft_solve(int col, int line, t_conditions cond, int grid[4][4]);
#endif
