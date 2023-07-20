/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:50:06 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/17 18:54:39 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char **strs, int size)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < size)
	{
		while (strs[i][len])
			len++;
		i++;
	}
	return (len);
}

char	*ft_join(int size, char **strs, char *sep, char *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		if (i != size - 1)
		{
			while (sep[j])
			{
				str[k] = sep[j];
				j++;
				k++;
			}
		}
		i++;
	}
	str[k] = '\0';
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		len_tt;

	if (!size)
	{
		str = malloc(sizeof(char) * 1);
		if (!str)
			return (NULL);
		str = NULL;
		return (str);
	}
	len_tt = ft_strlen(strs, size) + (ft_strlen(&sep, 1) * (size - 1));
	str = malloc(sizeof(char) * (len_tt + 1));
	if (!str)
		return (NULL);
	str = ft_join(size, strs, sep, str);
	return (str);
}
