/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerbidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:45:43 by jkerbidi          #+#    #+#             */
/*   Updated: 2022/07/31 20:32:16 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_error(int argc, char **argv)
{
	if (argc != 2 && argc != 3)
		return (-1);
	if (!ft_str_is_numeric(argv[argc - 1]))
		return (-1);
	return (0);
}
