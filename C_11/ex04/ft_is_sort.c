/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:02:51 by thdoenle          #+#    #+#             */
/*   Updated: 2022/08/04 00:20:36 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	is_sort;
	int	is_sort_rev;

	is_sort = 1;
	is_sort_rev = 1;
	while (length > 1)
	{
		if ((*f)(tab[0], tab[1]) > 0)
			is_sort = 0;
		if ((*f)(tab[0], tab[1]) < 0)
			is_sort_rev = 0;
		tab++;
		length--;
	}
	if (is_sort || is_sort_rev)
		return (1);
	return (0);
}
