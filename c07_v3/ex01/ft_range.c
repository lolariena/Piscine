/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 21:58:37 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/11 22:04:50 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	i;

	if (min >= max)
		return (0);
	tab = malloc((max - min) * sizeof(int));
	if (!tab)
		return (0);
	i = 0;
	while (i + min < max)
	{
		tab[i] = min + i;
		i++;
	}
	return (tab);
}
