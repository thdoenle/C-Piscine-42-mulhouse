/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 13:45:12 by thdoenle          #+#    #+#             */
/*   Updated: 2022/08/01 14:28:05 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_abs(unsigned int nb)
{
	if (nb != 0)
	{
		ft_putnbr_abs(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
}

void	ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr_abs(-nb);
	}
	else if (nb == 0)
	{
		ft_putchar('0');
	}
	else
		ft_putnbr_abs(nb);
}

void	ft_putstr(char *str)
{
	while (*str)
	{
		ft_putchar(*str);
		str++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	if (par == 0)
		return ;
	while (par->str)
	{
		ft_putstr(par->str);
		ft_putchar('\n');
		ft_putnbr(par->size);
		ft_putchar('\n');
		ft_putstr(par->copy);
		ft_putchar('\n');
		par++;
	}
}
