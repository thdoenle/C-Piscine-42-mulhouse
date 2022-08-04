/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:36:40 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/31 19:47:42 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	jump_spaces(int fd, char *c_ptr)
{
	while (*c_ptr == ' ')
		*c_ptr = get_next_char(fd);
}

int	read_dict(int fd, char **key, char **value)
{
	char	c;

	c = get_next_char(fd);
	while (c)
	{
		while (ft_is_wspace(c))
			c = get_next_char(fd);
		if (parse_key(fd, key, &c) == -1)
			return (-1);
		jump_spaces(fd, &c);
		if (c != ':')
			return (-1);
		c = get_next_char(fd);
		jump_spaces(fd, &c);
		if (!ft_is_printable(c) || parse_value(fd, value, &c) == -1)
			return (-1);
		while (ft_is_wspace(c))
			c = get_next_char(fd);
		key++;
		value++;
	}
	return (0);
}

int	parse_dict(char *name, char ***k_ptr, char ***v_ptr)
{
	int		fd;
	int		nb_l;

	nb_l = calc_nb_lines(name);
	if (nb_l < 41)
		return (-1);
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	if (alloc_init_dict(k_ptr, v_ptr, nb_l) == -1)
	{
		close(fd);
		return (-1);
	}
	if (read_dict(fd, *k_ptr, *v_ptr) == -1)
	{
		close(fd);
		return (free_dict(*k_ptr, *v_ptr));
	}
	close(fd);
	if (sort_dict(*k_ptr, *v_ptr) == -1)
		return (free_dict(*k_ptr, *v_ptr));
	return (0);
}
