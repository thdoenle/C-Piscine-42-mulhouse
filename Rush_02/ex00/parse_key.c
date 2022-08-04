/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:07:36 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/31 18:08:09 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	parse_key_jump_zeros(int fd, char **key, char c)
{
	while (c == '0')
		c = get_next_char(fd);
	if (c < '1' || c > '9')
	{
		if (**key != '-')
			*key = str_append(*key, '0');
		else
			**key = '0';
	}
	return (c);
}

int	parse_key(int fd, char **key, char *c_ptr)
{
	if (add_empty_str(key) == -1)
		return (-1);
	if (*c_ptr == '-')
		*key = str_append(*key, '-');
	if (*c_ptr == '-' || *c_ptr == '+')
		*c_ptr = get_next_char(fd);
	if (*c_ptr == '0')
		*c_ptr = parse_key_jump_zeros(fd, key, *c_ptr);
	else if (*c_ptr < '1' || *c_ptr > '9')
		return (-1);
	while (*c_ptr >= '0' && *c_ptr <= '9')
	{
		*key = str_append(*key, *c_ptr);
		*c_ptr = get_next_char(fd);
	}
	return (0);
}
