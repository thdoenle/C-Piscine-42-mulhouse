/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:00:11 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/19 17:26:19 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa(unsigned char c)
{
	unsigned char	temp;

	write(1, "\\", 1);
	temp = c / 16;
	if (temp < 10)
		ft_putchar(temp + '0');
	else
		ft_putchar(temp + 87);
	temp = c % 16;
	if (temp < 10)
		ft_putchar(temp + '0');
	else
		ft_putchar(temp + 87);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str < 32 || *str == 127)
			ft_print_hexa(*str);
		else
			write(1, str, 1);
		str++;
	}
}
