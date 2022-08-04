/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:47:06 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/19 13:32:14 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_hexa(unsigned long nbr, int nb_d)
{
	char	*str;

	str = "0123456789abcdef";
	if (nb_d > 1)
		ft_print_hexa(nbr / 16, nb_d - 1);
	ft_putchar(str[nbr % 16]);
}

void	ft_print_characters_hexa(unsigned char *c_ptr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && i < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		ft_print_hexa((unsigned long)*c_ptr, 2);
		c_ptr++;
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 0)
			ft_putchar(' ');
		ft_putchar(' ');
		ft_putchar(' ');
		i++;
	}
}

void	ft_print_characters(unsigned char *c_ptr, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < size && i < 16)
	{
		if ((char)*c_ptr < 32 || *c_ptr == 127)
			ft_putchar('.');
		else
			ft_putchar(*c_ptr);
		c_ptr++;
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)addr;
	while (size)
	{
		ft_print_hexa((unsigned long)ptr, 16);
		ft_putchar(':');
		ft_print_characters_hexa(ptr, size);
		ft_putchar(' ');
		ft_print_characters(ptr, size);
		ft_putchar('\n');
		if (size < 16)
			size = 0;
		else
		{
			size -= 16;
			ptr += 16;
		}
	}
	return (addr);
}
