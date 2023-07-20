/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:44:04 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/06 17:16:22 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	tmp;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	tmp = 1;
	while (power)
	{
		tmp = tmp * nb;
		power--;
	}
	return (tmp);
}
