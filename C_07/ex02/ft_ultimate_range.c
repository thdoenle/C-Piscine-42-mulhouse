/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 18:14:37 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/28 14:51:04 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	*tab;

	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = max - min;
	tab = malloc(sizeof(*tab) * size);
	if (tab == 0)
		return (-1);
	*range = tab;
	while (min < max)
	{
		*tab = min;
		min++;
		tab++;
	}
	return (size);
}
