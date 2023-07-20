/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:39:15 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/17 15:55:13 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	range[0] = malloc((max - min) * sizeof(int));
	if (!range[0])
		return (-1);
	i = 0;
	while (i + min < max)
	{
		range[0][i] = min + i;
		i++;
	}
	return (max - min);
}
