/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryanik <eryanik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:33:48 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/16 23:12:43 by eryanik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_get_nbr(char *ln)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (ln[i] && ln[i] >= 48 && ln[i] <= 57)
	{
		n = n * 10 + ln[i] - 48;
		i++;
	}
	return (n);
}

char	*ft_get_str(char *ln)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	j = 0;
	while (ln[i] && ln[i] >= 48 && ln[i] <= 57)
		i++;
	while (ln[i] && (ln[i] == 32 || ln[i] == ':'))
		i++;
	len = 0;
	while (ln[i + j])
	{
		if (ln[i + j] != 32 || (ln[i + j] == 32 && ln[i + j - 1] != 32))
			len++;
		j++;
	}
	str = malloc((1 + len) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (ln[i])
	{
		if (ln[i] != 32 || (ln[i] == 32 && ln[i - 1] != 32))
		{
			str[j] = ln[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

t_dict	*ft_add_dict(int n, char *str, t_dict *last)
{
	t_dict	*new;

	new = malloc(sizeof(t_dict));
	if (!new)
		return (NULL);
	new->n = n;
	new->str = str;
	new->nxt = NULL;
	last->nxt = new;
	return (new);
}

t_dict	*ft_init_list(int n, char *str)
{
	t_dict	*first;

	first = malloc(sizeof(t_dict));
	if (!first)
		return (NULL);
	first->n = n;
	first->str = str;
	first->nxt = NULL;
	return (first);
}

t_dict	*ft_create_dict(char *ln, t_list dict)
{
	t_dict	*last;
	int		n;
	char	*str;

	if (!ft_check_ln(ln))
		return (NULL);
	n = ft_get_nbr(ln);
	str = ft_get_str(ln);
	if (!str)
		return (NULL);
	if (dict.first == NULL)
	{
		dict.first = ft_init_list(n, str);
		if (dict.first == NULL)
			return (NULL);
	}
	else
	{
		if (!ft_check_double(n, dict->first))
			return (NULL);
		last = ft_last_dict(dict.first);
		if (!ft_add_dict(n, str, last))
			return (NULL);
	}
	return (dict.first);
}
