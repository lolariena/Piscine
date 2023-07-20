/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtixier <vtixier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:01:53 by vtixier           #+#    #+#             */
/*   Updated: 2023/07/09 15:59:26 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH01_H
# define RUSH01_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_conditions
{
	int	colup[9];
	int	coldown[9];
	int	rowleft[9];
	int	rowright[9];
	int	size;
}	t_conditions;

void		ft_error(void);
int			ft_check_arg(char *str);
void		ft_set_conditions(char *str, t_conditions *conditions);
int			**ft_init_tab(int size);
void		ft_put_grid(int **grid, int size);
int			ft_check_line(int *tab, int line, t_conditions conditions);
int			ft_check_col(int **tab, int col, t_conditions conditions);
int			ft_check_occ_ln(int *tab, int index, int size);
int			ft_check_occ_cl(int **tab, int ln_index, int cl_index, int size);
int			ft_solve(int col, int line, t_conditions cond, int **grid);
int			ft_isnum(char c, int size);
#endif
