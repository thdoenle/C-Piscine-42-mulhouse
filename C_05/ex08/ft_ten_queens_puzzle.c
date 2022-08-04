/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:37:18 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/23 14:59:29 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_is_possible(char *tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (tab[i] == tab[n]
			|| tab[i] - tab[n] + n - i == 0
			|| tab[i] - tab[n] + i - n == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_sol(char *tab, int i, int nb_sol)
{
	if (i == 10)
	{
		write(1, tab, 11);
		return (nb_sol + 1);
	}
	tab[i] = '0';
	while (tab[i] <= '9')
	{
		if (ft_is_possible(tab, i))
			nb_sol = ft_find_sol(tab, i + 1, nb_sol);
		(tab[i])++;
	}
	return (nb_sol);
}

int	ft_ten_queens_puzzle(void)
{
	char	tab[11];

	tab[10] = '\n';
	return (ft_find_sol(tab, 0, 0));
}
