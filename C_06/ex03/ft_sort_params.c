/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 11:46:16 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/24 12:15:13 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_nl(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

void	ft_swap(char **strs, int i)
{
	char	*temp;

	temp = strs[i];
	strs[i] = strs[i + 1];
	strs[i + 1] = temp;
}

int	ft_is_greater(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	return (0);
}

void	ft_sort_strs(char **strs, int size)
{
	int	i;
	int	is_sorted;

	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		i = 0;
		while (i + 1 < size)
		{
			if (ft_is_greater(strs[i], strs[i + 1]))
			{
				ft_swap(strs, i);
				is_sorted = 0;
			}
			i++;
		}
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	ft_sort_strs(av + 1, ac - 1);
	while (i < ac)
	{
		ft_putstr_nl(av[i]);
		i++;
	}
}
