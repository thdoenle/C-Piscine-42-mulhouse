/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:30:08 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/20 17:56:22 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

unsigned int	ft_calc_base(char *base)
{
	unsigned int	len;
	unsigned int	i;

	len = 0;
	while (base[len])
		len++;
	if (len < 2)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-')
			return (0);
		i = 1;
		while (base[i] && base[i] != *base)
			i++;
		if (base[i] == *base)
			return (0);
		base++;
	}
	return (len);
}

void	ft_print_nbr(unsigned int nbr, char *base, unsigned int b_len)
{
	if (nbr >= b_len)
		ft_print_nbr(nbr / b_len, base, b_len);
	ft_putchar(base[nbr % b_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	base_len;

	base_len = ft_calc_base(base);
	if (base_len == 0)
		return ;
	if (nbr < 0)
	{
		ft_putchar('-');
		ft_print_nbr(-nbr, base, base_len);
	}
	else
		ft_print_nbr(nbr, base, base_len);
}
