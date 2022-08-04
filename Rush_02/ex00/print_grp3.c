/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grp3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:49:42 by amouly            #+#    #+#             */
/*   Updated: 2022/07/31 20:11:43 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	power_space(int power)
{
	if (power != 0)
		ft_putstr(" ");
}

void	print_grp3_cent(char *nbr, char **tens, char **units, int power)
{
	power_space(power);
	ft_putstr(units[nbr[0] - 48]);
	ft_putstr(" ");
	ft_putstr(tens[8]);
}

void	print_grp3(char *nbr, char **tens, char **units, int power)
{
	if (nbr[0] != '0')
		print_grp3_cent(nbr, tens, units, power);
	if (nbr[1] != '0' && nbr[1] != '1')
	{
		power_space(power);
		if (power == 0 && nbr[0] != '0')
			ft_putstr(" ");
		ft_putstr(tens[nbr[1] - 48 - 2]);
	}
	if (nbr[1] == '1')
	{
		power_space(power);
		if (power == 0 && nbr[0] != '0')
			ft_putstr(" ");
		ft_putstr(units[nbr[2] - 48 + 10]);
	}
	if (nbr[2] != '0' && nbr[1] != '1')
	{
		power_space(power);
		if (power == 0 && (nbr[0] != '0' || nbr[1] != '0'))
			ft_putstr(" ");
		ft_putstr(units[nbr[2] - 48]);
	}
}
