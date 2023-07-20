/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:38:18 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/16 21:53:49 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int		ft_test_free(char *to_test, char *to_free)
{
	if (!to_test)
	{
		free(to_free);
		return (1);
	}
	return (0);
}

char	*ft_copy(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_init_ln(char *src, char	*dst)
{
	dst = ft_copy(dst, src);
	free(src);
	src = malloc(sizeof(char));
	if (ft_test_free(src, dst))
		return (NULL);
	src[0] = '\0';
	return (src);
}

t_dict	*ft_last_dict(t_dict *current)
{
	if (!current->nxt)
		return (current);
	return (ft_last_dict(current->nxt));
}

