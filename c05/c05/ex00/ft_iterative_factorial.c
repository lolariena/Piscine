/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:29:54 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/06 15:21:36 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	res;

	if (nb > 0)
	{
		res = 1;
		i = 1;
		while (i <= nb)
		{
			res = res * i;
			i++;
		}
		return (res);
	}
	else if (nb == 0)
		return (1);
	return (0);
}
