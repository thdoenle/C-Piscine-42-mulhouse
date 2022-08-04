/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnumber.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerbidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:15:03 by jkerbidi          #+#    #+#             */
/*   Updated: 2022/07/24 13:09:13 by jkerbidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_putnumber(int nb)
{
	if (nb <= 9 && nb >= 0)
	{
		nb += '0';
		ft_putchar(nb);
	}
}