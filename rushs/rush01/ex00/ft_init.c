/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 14:13:09 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/08 15:07:01 by aibonade         ###   ########.fr       */
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

/*int	main()
{
	int	t[4][4];
    int i;
    int j;

	ft_init_tab(t);
    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
			printf("tab[%d][%d] = %d\n", i, j, t[i][j]);
            j++;
        }
        i++;
    }

	return (0);
}*/
