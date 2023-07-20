/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_conditions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtixier <vtixier@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/08 12:05:42 by nrea              #+#    #+#             */
/*   Updated: 2023/07/08 14:53:53 by vtixier          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

void	ft_set_con_columns(char *str, t_conditions *conditions)
{
	int	i;
	int	offset;

	offset = 0;
	i = 0;
	while (i <= 6)
	{
		conditions->colup[i / 2] = str[i + offset] - 48;
		i += 2;
	}
	i = 0;
	offset = 8;
	while (i <= 6)
	{
		conditions->coldown[i / 2] = str[i + offset] - 48;
		i += 2;
	}
}

void	ft_set_con_rows(char *str, t_conditions *conditions)
{
	int	i;
	int	offset;

	i = 0;
	offset = 16;
	while (i <= 6)
	{
		conditions->rowleft[i / 2] = str[i + offset] - 48;
		i += 2;
	}
	i = 0;
	offset = 24;
	while (i <= 6)
	{
		conditions->rowright[i / 2] = str[i + offset] - 48;
		i += 2;
	}
}

void	ft_set_conditions(char *str, t_conditions *conditions)
{
	ft_set_con_columns(str, conditions);
	ft_set_con_rows(str, conditions);
}
/*
#include<stdio.h>
int main()
{
struct s_conditions conditions;
char str_test[] =  "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";

ft_set_conditions(str_test, &conditions);

int i = 0;
while(i<4)
{
printf("%d",conditions.colup[i]);
i++;
}
printf("\n");
i = 0;
while(i<4)
{
printf("%d",conditions.coldown[i]);
i++;
}
printf("\n");
i = 0;
while(i<4)
{
printf("%d",conditions.rowleft[i]);
i++;
}
printf("\n");
i = 0;
while(i<4)
{
printf("%d",conditions.rowright[i]);
i++;
}
	return 0;
}*/
