/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testnum.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryanik <eryanik@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 19:35:43 by eryanik           #+#    #+#             */
/*   Updated: 2023/07/16 23:35:35 by eryanik          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	handlemultiples(int b, long int tab[], int *c)
{
	if (b == 3)
		tab[++(*c)] = 1000;
	else if (b == 6)
		tab[++(*c)] = 1000000;
	else if (b == 9)
		tab[++(*c)] = 1000000000;
}

void	handleinrange(long int n, int a, long int tab[], int *c)
{
	if (n % a > 100 && n % a < 1000)
	{
		tab[++(*c)] = 100;
		tab[++(*c)] = n % a / 100;
		n /= 1000;
		a /= 1000;
	}
	else if (n % a == 100)
	{
		tab[++(*c)] = 100;
		n /= 1000;
		a /= 1000;
	}
}

void	handlethousandscase(long int n, int a, long int tab[], int *c)
{
	if (n % a > 999)
	{
		tab[++(*c)] = n % a / 1000;
		n /= 1000;
		a /= 1000;
	}
	else if (n % a > 999999)
	{
		tab[++(*c)] = n % a / 1000000;
		n /= 1000;
		a /= 1000;
	}
}

int	function(long int n)
{
	int			a;
	int			b;
	long int	tab[20];
	int			c;

	a = 10;
	b = 0;
	c = -1;
	while (n != 0)
	{
		handlemultiples(b, tab, &c);
		handleinrange(n, a, tab, &c);
		handlethousandscase(n, a, tab, &c);
		if (n % (a * 10) < 20 && n % (a * 10) > 0)
		{
			tab[++c] = n % (a * 10);
			a = a * 10;
			b++;
		}
		else if (n % a > 0)
			tab[++c] = n % a;
		n = (n / a) * a;
		a = a * 10;
		b++;
	}
}
