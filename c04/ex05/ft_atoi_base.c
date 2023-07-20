/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:01:51 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/06 14:12:26 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_passspaces(char *str, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		if (str[i] == 43 || str[i] == 45)
			return (i);
		j = 0;
		while (base[j])
		{
			if (str[i] == base[j])
				return (i);
			j++;
		}
		if (str[i] < 9 || (str[i] > 13 && str[i] != 32))
			return (-1);
		i++;
	}
	return (-1);
}

int	ft_sign(char *str, int i, int *s, char *base)
{
	int	j;

	while (str[i])
	{
		if (str[i] == '-')
			*s = *s * (-1);
		else
		{
			j = 0;
			while (base[j])
			{
				if (str[i] == base[j])
					return (i);
				j++;
			}
		}
		if (str[i] != '+' && str[i] != '-')
			return (-1);
		i++;
	}
	return (-1);
}

int	ft_baseverif(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == 43 || base[i] == 45)
			return (0);
		if ((base[i] > 8 && base[i] < 14) || base[i] == 32)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_setnbr(char *str, char *base)
{
	int	i;
	int	len;
	int	j;
	int	nb;

	len = 0;
	while (base[len])
		len++;
	j = 0;
	nb = 0;
	while (str[j])
	{
		i = 0;
		while (base[i] && base[i] != str[j])
			i++;
		if (i == len)
			return (nb);
		nb = nb * len + i;
		j++;
	}
	return (nb);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	neg;

	if (!str)
		return (0);
	nb = 0;
	neg = 1;
	if (ft_baseverif(base))
	{
		i = ft_passspaces(str, base);
		if (i == -1)
			return (nb);
		i = ft_sign(str, i, &neg, base);
		if (i < 0)
			return (nb);
		nb = ft_setnbr(&str[i], base);
	}
	return (nb * neg);
}
