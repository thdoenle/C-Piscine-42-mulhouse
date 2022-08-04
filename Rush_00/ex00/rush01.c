/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:06:04 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/16 22:21:01 by thdoenle         ###   ########.fr       */
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
			if ((c == 0 && l == 0)
				|| (c == x - 1 && l == y - 1 && x > 1 && y > 1))
				ft_putchar('/');
			else if ((c == x - 1 && l == 0) || (c == 0 && l == y - 1))
				ft_putchar('\\');
			else if (l == 0 || l == y - 1 || c == 0 || c == x - 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}
