/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 17:30:22 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/07 14:15:30 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power -1));
}

int	ft_sqrt(int nb)
{
	int	i;

	if (nb < 0)
		return (0);
	if (nb < 2)
		return (nb);
	if (nb < 122)
	{
		i = 2;
		while (i < nb)
		{
			if (ft_recursive_power(i, 2) == nb)
				return (i);
			i++;
		}
	}
	i = 12;
	while (i < nb / 11)
	{
		if (ft_recursive_power(i, 2) == nb)
			return (i);
		i++;
	}
	return (0);
}
