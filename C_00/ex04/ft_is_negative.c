/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 18:19:04 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/13 18:24:09 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	result;

	result = 'P';
	if (n < 0)
	{
		result = 'N';
	}
	write(1, &result, 1);
}
