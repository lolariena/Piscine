/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibonade <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:44:33 by aibonade          #+#    #+#             */
/*   Updated: 2023/07/02 13:20:38 by aibonade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalphanum(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	if (c >= 'a' && c <= 'z')
		return (2);
	if (c >= '0' && c <= '9')
		return (3);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	alpha;
	int	prv;

	if (!str)
		return (0);
	prv = 0;
	while (str[i])
	{
		alpha = ft_isalphanum(str[i]);
		if (alpha == 1)
		{
			if (prv != 0)
				str[i] += 32;
		}
		if (alpha == 2)
		{	
			if (prv == 0)
				str[i] -= 32;
		}
		prv = alpha;
		i++;
	}
	return (str);
}
