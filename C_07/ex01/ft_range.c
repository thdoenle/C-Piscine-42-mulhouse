/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 17:57:01 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/28 14:50:44 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int	*ptr;

	if (min >= max)
		return (0);
	tab = malloc(sizeof(*tab) * (max - min));
	if (tab == 0)
		return (0);
	ptr = tab;
	while (min < max)
	{
		*ptr = min;
		ptr++;
		min++;
	}
	return (tab);
}
