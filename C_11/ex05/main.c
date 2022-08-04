/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:19:03 by thdoenle          #+#    #+#             */
/*   Updated: 2022/08/03 04:08:49 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_op.h"

void	ft_unknown(int a, int b)
{
	(void)a;
	(void)b;
	write(1, "0", 1);
}

int	ft_find_index(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

void	(*ft_get_ft(char *op))(int a, int b)
{
	void	(*ft_tab[6])(int, int);

	ft_tab[0] = &ft_sum;
	ft_tab[1] = &ft_sub;
	ft_tab[2] = &ft_mult;
	ft_tab[3] = &ft_div;
	ft_tab[4] = &ft_mod;
	ft_tab[5] = &ft_unknown;
	if (op[0] == '\0' || op[1] != '\0')
		return (ft_tab[5]);
	return (ft_tab[ft_find_index(*op, "+-*/%")]);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	(*ft_get_ft(av[2]))(ft_atoi(av[1]), ft_atoi(av[3]));
	write(1, "\n", 1);
}
