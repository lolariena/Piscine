/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 13:44:24 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/18 16:40:13 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_atoi_base(char *str, char *base);
int	ft_passspaces(char *str, char *base);
int	ft_sign(char *str, int i, int *s, char *base);
int	ft_baseverif(char *base);

int	ft_strlen(long int *nb, int base_len, int *neg)
{
	int		ln;
	long	tmp;

	ln = 0;
	*neg = 0;
	if (*nb < 0)
	{
		*neg = 1;
		*nb = -1 * *nb;
		ln++;
	}
	tmp = *nb;
	while (tmp)
	{
		tmp = tmp / base_len;
		ln++;
	}
	return (ln);
}

int	ft_baseverif_itoa(char *base)
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

char	*ft_zero(char *base_from, char *base_to)
{
	char	*str;

	if (!ft_baseverif(base_from))
		return (NULL);
	str = NULL;
	str = malloc(2 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = base_to[0];
	str[1] = '\0';
	return (str);
}

char	*ft_itoa_base(long int n, char *base)
{
	int		ln_base;
	int		ln_str;
	char	*str;
	int		i;
	int		neg;

	ln_base = 0;
	while (base[ln_base])
		ln_base++;
	ln_str = ft_strlen(&n, ln_base, &neg);
	str = malloc((ln_str + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 1;
	while (n)
	{
		str[ln_str - i] = base[n % ln_base];
		n = n / ln_base;
		i++;
	}
	if (neg)
		str[0] = '-';
	str[ln_str] = '\0';
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*str;

	str = NULL;
	nb = ft_atoi_base(nbr, base_from);
	if (ft_baseverif_itoa(base_to))
	{
		if (nb == 0)
			str = ft_zero(base_from, base_to);
		else
			str = ft_itoa_base(nb, base_to);
	}
	return (str);
}
