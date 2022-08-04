/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 02:53:35 by thdoenle          #+#    #+#             */
/*   Updated: 2022/08/03 04:48:18 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	*new;
	int	*ptr;

	if (length <= 0)
		return (0);
	new = malloc(sizeof(*new) * length);
	if (new == 0)
		return (0);
	ptr = new;
	while (length)
	{
		*ptr = (*f)(*tab);
		tab++;
		ptr++;
		length--;
	}
	return (new);
}
