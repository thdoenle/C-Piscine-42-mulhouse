/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flmartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:35:12 by flmartin          #+#    #+#             */
/*   Updated: 2022/07/16 22:07:04 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	c;
	int	l;

	l = 0;
	while (l < y)
	{
		c = 0;
		while (c < x)
		{
			if (c == 0 && (l == 0 || l == y - 1))
				ft_putchar('A');
			else if (c == x - 1 && (l == 0 || l == y - 1))
				ft_putchar('C');
			else if (c == 0 || c == x - 1 || l == 0 || l == y - 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}
