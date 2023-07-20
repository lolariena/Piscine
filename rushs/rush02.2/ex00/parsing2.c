/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 22:26:30 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/16 22:40:22 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rush02.h>

int	ft_check_double(int n, t_dict *current)
{
	if (current->n == n)
		return (0);
	if (current->nxt == NULL)
		return (1);
	if (current->nxt && ft_check_double(n, current->nxt))
		return (1);
	return (0);
}
