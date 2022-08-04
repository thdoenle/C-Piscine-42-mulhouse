/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_nb_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:16:50 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/31 21:01:13 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	calc_nb_lines_increase(int *nb_ptr, char *c_ptr, int fd, int *is_e_ptr)
{
	if (*c_ptr != '\n' && !ft_is_wspace(*c_ptr))
		*is_e_ptr = 0;
	if (*c_ptr == '\n' && !*is_e_ptr)
	{
		(*nb_ptr)++;
		*is_e_ptr = 1;
	}
	*c_ptr = get_next_char(fd);
}

int	calc_nb_lines(char *name)
{
	int		nb;
	int		fd;
	int		is_empty;
	char	c;

	nb = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
		return (-1);
	is_empty = 1;
	c = get_next_char(fd);
	while (c > 0)
		calc_nb_lines_increase(&nb, &c, fd, &is_empty);
	if (!is_empty)
		nb++;
	close(fd);
	if (c == -1)
		return (-1);
	return (nb);
}
