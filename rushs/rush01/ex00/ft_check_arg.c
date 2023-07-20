/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtixier <vtixier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 11:20:54 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/08 18:35:26 by nrea             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

int	ft_isnum(char c)
{
	if (c < '1' || c > '4')
		return (0);
	return (1);
}

int	ft_check_firstlast(char c)
{
	if (ft_isnum(c))
		return (1);
	return (0);
}

int	ft_check_arg(char *str)
{
	int	nbw;
	int	i;

	nbw = 0;
	if (ft_check_firstlast(str[0]))
		nbw += 1;
	else
		return (0);
	i = 0;
	while (str[++i])
	{
		if (ft_isnum(str[i]) && str[i - 1] == 32)
			nbw++;
		else
		{
			if (!(str[i] == 32 && str[i - 1] != 32))
				return (0);
		}
	}
	if (!ft_check_firstlast(str[i - 1]))
		return (0);
	return (nbw);
}
