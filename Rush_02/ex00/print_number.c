/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:45:22 by amouly            #+#    #+#             */
/*   Updated: 2022/07/31 21:07:34 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_tablen(char **grp3)
{
	int	a;

	a = 0;
	while (grp3[a] != 0)
		a++;
	return (a);
}	

void	print_number(char **grp3, char **units, char **tens, char **powers)
{
	int	a;
	int	b;
	int	c;

	a = 0;
	b = 0;
	a = ft_tablen(grp3);
	c = a;
	while (b < a)
	{
		print_grp3(grp3[b], tens, units, b);
		if (b != a - 1)
		{
			if (!(grp3[b][0] == '0' && grp3[b][1] == '0' && grp3[b][2] == '0'))
			{
				ft_putstr(" ");
				if (c > 13)
					ft_putstr(powers[a % 13 - 2 - b]);
				else
					ft_putstr(powers[a - 2 - b]);
			}
		}
		b++;
		c--;
	}
}
