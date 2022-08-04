/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amouly <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 12:11:58 by amouly            #+#    #+#             */
/*   Updated: 2022/07/31 23:34:01 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_tab_vide(char **tab, int size)
{
	int	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	if (size != i)
		return (1);
	return (0);
}

char	**fill_tab_unit(char **keys, char **values)
{
	int		i;
	int		a;
	char	**ret;

	i = 0;
	a = 0;
	ret = malloc(sizeof(char *) * 21);
	while (!(keys[i][0] == 48 && keys[i][1] == 0))
		i++;
	while (a < 10)
	{
		ret[a] = ft_strcpy_malloc(ret[a], values[i]);
		a++;
		i++;
	}
	while ((keys[i][0] != 49) || (keys [i][1] != 48))
		i++;
	while (a < 20)
	{
		ret[a] = ft_strcpy_malloc(ret[a], values[i]);
		a++;
		i++;
	}
	ret[a] = 0;
	return (ret);
}

int	is_hundred(char a, char b, char c, char d)
{
	if (a == 49 && b == 48 && c == 48 && d == 0)
		return (1);
	return (0);
}

char	**fill_tab_tens(char **keys, char **values)
{
	int		i;
	int		a;
	int		com;
	char	**ret;

	i = 0;
	a = 0;
	com = 50;
	ret = malloc(sizeof(char *) * 10);
	while (!(keys[i][0] == 50 && keys[i][1] == 48 && keys[i][2] == 0))
		i++;
	while (!(keys[i][0] == 49 && keys[i][1] == 48
				&& keys[i][2] == 48 && keys[i][3] == 0))
	{
		if (keys[i][0] == com && keys[i][1] == 48 && keys[i][2] == 0 && com++)
		{
			ret[a] = ft_strcpy_malloc(ret[a], values[i]);
			a++;
		}
		i++;
	}
	if (is_hundred(keys[i][0], keys[i][1], keys[i][2], keys[i][3]))
		ret[a] = ft_strcpy_malloc(ret[a], values[i]);
	ret[9] = 0;
	return (ret);
}

char	**fill_tab_power(char **keys, char **values)
{
	int		i;
	int		a;
	int		len_str;
	char	**ret;

	i = 0;
	a = 0;
	len_str = 4;
	ret = malloc(sizeof(char *) * 13);
	while ((ft_strlen(keys[i]) < 4))
		i++;
	while (keys[i] != 0)
	{
		if (keys[i][0] == 49 && ft_strlen(keys[i]) == len_str
				&& ft_is_zero(&keys[i][1]))
		{
			ret[a] = ft_strcpy_malloc(ret[a], values[i]);
			a++;
			len_str = len_str + 3;
		}
		i++;
	}
	ret[a] = 0;
	return (ret);
}
