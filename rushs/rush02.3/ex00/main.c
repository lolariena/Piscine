/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 23:04:59 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/16 23:40:29 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rush02.h"

t_list	*ft_get_dict(char *file, number)
{
	t_list	*dict;
	int		fd;
	
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return (NULL);
	}
	
	dict = ft_dict_parsing(fd);
	if (!dict)
	{
		write(1, "Dict Error\n", 11);
		return (NULL);
	}
	return (dict);
}

t_dict	*ft_search_nbr(int n, t_dict current)
{
	if (current->n == n)
		return (&current);
	if (current->nxt == NULL)
		return (NULL);
	return ft_search_nbr(n, current->nxt);
}

int	ft_printnbr(tab[i], t_list dict)
{
//search	
}

void	ft_putnbr(int number, t_list dict)
{
	long int	tab[20];
	int			i;

	tab = function(number);
	i = 0;
	while (tab[i] != -1)
	{
		if (!ft_printnbr(tab[i], dict))
		{
			write(1, "Dict Error\n", 11);
			return ;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	number;
	t_list	*dict;
	char *file;

	if (argc == 2)
	{
		number = ft_atoi(argv[1]);
		file = "numbers.dict";
	}
	else if (argc == 3)
	{
		number = ft_atoi(argv[2]);
		file = argv[1];
	}
	if (number < 0 || argc < 2 || argc > 3)
		write(1, "Error\n", 6);
	dict = ft_get_dict(file);
	if (!dict)
		return(0);
	ft_putnbr(number, dict);
	ft_free_dict(dict->first);
	free(dict);
	return (0);
}
