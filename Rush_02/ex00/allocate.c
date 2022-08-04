/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:59:13 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/31 18:03:30 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	alloc_init_dict(char ***k_ptr, char ***v_ptr, int nb_l)
{
	*k_ptr = malloc(sizeof(**k_ptr) * (nb_l + 1));
	if (*k_ptr)
		**k_ptr = 0;
	*v_ptr = malloc(sizeof(**v_ptr) * (nb_l + 1));
	if (*v_ptr)
		**v_ptr = 0;
	if (*k_ptr == 0 || *v_ptr == 0)
		return (-1);
	return (0);
}
