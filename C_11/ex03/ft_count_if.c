/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:00:40 by thdoenle          #+#    #+#             */
/*   Updated: 2022/08/03 04:48:42 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	count;

	count = 0;
	while (length > 0)
	{
		if ((*f)(*tab))
			count++;
		length--;
		tab++;
	}
	return (count);
}
