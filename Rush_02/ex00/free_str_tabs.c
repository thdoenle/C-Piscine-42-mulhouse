/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_tabs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:57:47 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/31 19:13:14 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	free_dict(char **keys, char **values)
{
	char	**ptr;

	if (keys)
	{
		ptr = keys;
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(keys);
	}
	if (values)
	{
		ptr = values;
		while (*ptr)
		{
			free(*ptr);
			ptr++;
		}
		free(values);
	}
	return (-1);
}
