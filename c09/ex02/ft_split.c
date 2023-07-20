/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 20:24:53 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/13 23:32:46 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (c == sep[i])
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_words(char	*str, char *sep)
{
	int	nbw;
	int	i;
	int	prv;
	int	is_sep;

	nbw = 0;
	i = 0;
	prv = 1;
	is_sep = 0;
	while (str[i])
	{
		is_sep = ft_is_sep(str[i], sep);
		if (!is_sep && prv)
			nbw++;
		prv = is_sep;
		i++;
	}
	return (nbw);
}

char	*ft_cut(char *str, int *i, char *sep)
{
	int		j;
	int		size;
	char	*nw_str;

	j = *i;
	size = 0;
	while (str[j] && !ft_is_sep(str[j], sep))
	{
		size++;
		j += 1;
	}
	nw_str = malloc((size + 1) * sizeof(char));
	if (!nw_str)
		return (NULL);
	j = 0;
	while (j < size)
	{
		nw_str[j] = str[*i];
		*i += 1;
		j++;
	}
	nw_str[j] = '\0';
	return (nw_str);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		size_res;
	int		i;
	int		j;

	size_res = ft_count_words(str, charset);
	res = malloc((size_res + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (i < size_res)
	{
		while (str[j] && ft_is_sep(str[j], charset))
			j++;
		res[i] = ft_cut(str, &j, charset);
		i++;
	}
	res[size_res] = 0;
	return (res);
}
