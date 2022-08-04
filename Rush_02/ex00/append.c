/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:06:06 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/31 18:06:37 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*str_append(char *str, char c)
{
	char	*new;
	int		i;

	new = malloc(sizeof(*new) * (ft_strlen(str) + 2));
	if (new == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = c;
	new[i + 1] = 0;
	free(str);
	return (new);
}

int	add_empty_str(char **s_ptr)
{
	*s_ptr = malloc(sizeof(**s_ptr));
	if (*s_ptr == 0)
		return (-1);
	**s_ptr = 0;
	s_ptr[1] = 0;
	return (0);
}
