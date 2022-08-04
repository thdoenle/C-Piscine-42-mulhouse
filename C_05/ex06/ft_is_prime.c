/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 21:42:42 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/23 02:11:09 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_prev_square(int nb)
{
	int	p;
	int	pp;

	p = 1;
	pp = 1;
	while (pp < nb && pp > 0)
	{
		p++;
		pp = p * p;
	}
	if (pp == nb)
		return (pp);
	return (p - 1);
}

int	ft_is_prime(int nb)
{
	int	p;
	int	i;

	if (nb < 2)
		return (0);
	if (nb < 4)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	p = ft_prev_square(nb);
	if (p == nb)
		return (0);
	i = 5;
	while (i <= p)
	{
		if (nb % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}
