/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:56:06 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/16 12:03:32 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	pouet;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
		pouet = -1;
		printf("Avant : nb = %d && power = %d && Pouet = %d\n",nb, power, pouet);
		pouet = nb * ft_recursive_power(nb, power -1);
		printf("Apres : nb = %d && power = %d && Pouet = %d\n\n",nb, power, pouet);
	return (pouet);
}
