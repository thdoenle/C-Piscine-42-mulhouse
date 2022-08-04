/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 15:26:57 by thdoenle          #+#    #+#             */
/*   Updated: 2022/08/01 14:27:40 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *str, int size)
{
	char	*copy;
	char	*ptr;

	copy = malloc(sizeof(*copy) * (size + 1));
	if (copy == 0)
		return (0);
	ptr = copy;
	while (*str)
	{
		*ptr = *str;
		ptr++;
		str++;
	}
	*ptr = 0;
	return (copy);
}

void	ft_init_struct(t_stock_str *st_ptr, char *str)
{
	st_ptr->size = ft_strlen(str);
	st_ptr->str = str;
	st_ptr->copy = ft_strdup(str, st_ptr->size);
}

void	ft_free_all(t_stock_str *ptr, t_stock_str *start)
{
	while (ptr != start)
	{
		ptr--;
		free(ptr->copy);
	}
	free(ptr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*tab;
	t_stock_str	*ptr;

	if (ac < 0)
		return (0);
	tab = malloc(sizeof(*tab) * (ac + 1));
	if (tab == 0)
		return (0);
	ptr = tab;
	while (ac > 0)
	{
		ft_init_struct(ptr, *av);
		if (ptr->copy == 0)
		{
			ft_free_all(ptr, tab);
			return (0);
		}
		ptr++;
		ac--;
		av++;
	}
	ptr->str = 0;
	return (tab);
}
