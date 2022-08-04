/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:21:04 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/31 18:21:38 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	parse_value(int fd, char **value, char *c_ptr)
{
	if (add_empty_str(value) == -1)
		return (-1);
	while (ft_is_printable(*c_ptr))
	{
		if (*c_ptr == ' ')
		{
			while (*c_ptr == ' ')
				*c_ptr = get_next_char(fd);
			if (*c_ptr != '\n')
				*value = str_append(*value, ' ');
		}
		else
		{
			*value = str_append(*value, *c_ptr);
			*c_ptr = get_next_char(fd);
		}
	}
	if (*c_ptr != 0 && *c_ptr != '\n')
		return (-1);
	return (0);
}
