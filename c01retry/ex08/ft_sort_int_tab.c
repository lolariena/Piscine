/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 19:43:39 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/11 18:46:42 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *n, int *m)
{
	int	tmp;

	tmp = *n;
	*n = *m;
	*m = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	j = 0;
	while (j < size - 1)
	{
		i = 0;
		while (i < size - 1)
		{
			if (tab[i] > tab[i +1])
				ft_swap(&tab[i], &tab[i + 1]);
			i++;
		}
		j++;
	}
}
