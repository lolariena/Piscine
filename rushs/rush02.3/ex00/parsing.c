/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryanik <eryanik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 21:33:13 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/16 23:10:27 by eryanik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_check_ln(char *ln)
{
	int	i;

	if (!ln[0])
		return (0);
	i = 0;
	if (ln[i] < 48 || ln[i] > 57)
		return (0);
	while (ln[i] && ln[i] >= 48 && ln[i] <= 57)
		i++;
	while (ln[i] && ln[i] == 32)
		i++;
	if (!ln[i] || ln[i] != ':')
		return (0);
	else
		i++;
	while (ln[i] && ln[i] == 32)
		i++;
	if (!ln[i] || ln[i] < 32 || ln[i] == 127)
		return (0);
	while (ln[i] && ln[i] >= 32 && ln[i] < 127)
		i++;
	if (ln[i])
		return (0);
	return (1);
}

void	ft_free_dict(t_dict *dict)
{
	if (dict->nxt)
		ft_free_dict(dict->nxt);
	free(dict->str);
	free(dict);
}

char	*ft_split_buff(char *buff, char *ln, t_list *dict, int buff_size)
{
	int	i;
	int	j;

	j = 0;
	while (ln[j])
		j++;
	i = -1;
	while (++i < buff_size)
	{
		ln[j] = buff[i];
		if (buff[i] == '\n')
		{
			ln[j] = '\0';
			dict->first = ft_create_dict(ln, *dict);
			if (!dict->first)
			{
				free(ln);
				ft_free_dict(dict->first);
				free(dict);
				return (NULL);
			}
			j = -1;
		}
		j++;
	}
	ln[j] = '\0';
	return (ln);
}

char	*ft_cut_buffer(char *buff, t_list *dict, int buff_size, char *rst)
{
	char	*ln;

	ln = malloc((ft_strlen(rst) + buff_size + 1) * sizeof(char));
	ln[0] = '\0';
	if (ft_test_free(ln, rst))
		return (NULL);
	if (rst[0] != '\0')
	{
		rst = ft_init_ln(rst, ln);
		if (!rst)
			return (NULL);
	}
	ln = ft_split_buff(buff, ln, dict, buff_size);
	if (ft_test_free(ln, rst))
		return (NULL);
	if (ln[0])
	{
		free(rst);
		rst = malloc((ft_strlen(ln) + 1) * sizeof(char));
		if (ft_test_free(rst, ln))
			return (NULL);
		rst = ft_copy(rst, ln);
	}
	free(ln);
	return (rst);
}

t_list	*ft_dict_parsing(int file)
{
	char	buff[100];
	char	*rst;
	t_list	*dict;
	int		rd;

	rst = malloc(sizeof(char));
	if (!rst)
		return (NULL);
	rst[0] = '\0';
	dict = malloc(sizeof(t_list));
	if (!dict)
	{
		free(rst);
		return (NULL);
	}
	dict->first = NULL;
	rd = 1;
	while (rd)
	{
		rd = read(file, buff, 100);
		if (rd == -1)
			return (NULL);
		rst = ft_cut_buffer(buff, dict, rd, rst);
		if (!rst)
			return (NULL);
	}
	free(rst);
	return (dict);
}
