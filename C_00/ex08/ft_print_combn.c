/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 20:19:32 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/15 11:29:55 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_new_digit(int n, char *d, int i)
{
	if (n >= 1)
	{
		while (d[i] <= '9' - (char)n + 1)
		{
			d[i + 1] = d[i] + 1;
			ft_new_digit(n - 1, d, i + 1);
			if (n == 1)
			{
				write(1, d, i + 1);
				if (d[0] != '9' - (char)i)
					write(1, ", ", 2);
			}
			d[i]++;
		}
	}
}

void	ft_print_combn(int n)
{
	char	d[11];

	d[0] = '0';
	ft_new_digit(n, d, 0);
}
