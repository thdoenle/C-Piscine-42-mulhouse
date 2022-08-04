/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:33:40 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/31 19:43:23 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_in_order(char *s1, char *s2)
{
	int	s1_len;
	int	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > s2_len)
		return (1);
	else if (s1_len < s2_len)
		return (0);
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (-1);
	if (*s1 > *s2)
		return (1);
	return (0);
}

void	swap_entries(char **key, char **value)
{
	char	*temp;

	temp = key[0];
	key[0] = key[1];
	key[1] = temp;
	temp = value[0];
	value[0] = value[1];
	value[1] = temp;
}

void	put_negatives_at_end(char **keys, char **values)
{
	int	is_sorted;
	int	i;

	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		i = 0;
		while (keys[i + 1] && values[i + 1])
		{
			if (keys[i][0] == '-' && keys[i + 1][0] != '-')
			{
				swap_entries(keys + i, values + i);
				is_sorted = 0;
			}
			i++;
		}
	}
}

int	sort_dict(char **keys, char **values)
{
	int	is_sorted;
	int	i;
	int	res;

	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		i = 0;
		while (keys[i + 1] && values[i + 1])
		{
			res = is_in_order(keys[i], keys[i + 1]);
			if (res == -1)
				return (-1);
			if (res)
			{
				swap_entries(keys + i, values + i);
				is_sorted = 0;
			}
			i++;
		}
	}
	put_negatives_at_end(keys, values);
	return (0);
}
