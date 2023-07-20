/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:01:51 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/05 15:04:51 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnum(char c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_passspaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 43 || str[i] == 45 || ft_isnum(str[i]))
			return (i);
		if (str[i] < 9 || (str[i] > 13 && str[i] != 32))
			return (-1);
		i++;
	}
	return (-1);
}

int	ft_sign(char *str, int i, int *s)
{
	while (str[i])
	{
		if (str[i] == '-')
			*s = *s * (-1);
		else if (ft_isnum(str[i]))
			return (i);
		else if (str[i] != '+')
			return (-1);
		i++;
	}
	return (-1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	neg;

	if (!str)
		return (0);
	nb = 0;
	neg = 1;
	i = ft_passspaces(str);
	if (i == -1)
		return (nb);
	i = ft_sign(str, i, &neg);
	if (i < 0)
		return (nb);
	while (str[i])
	{
		if (!ft_isnum(str[i]))
			return (nb * neg);
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * neg);
}
