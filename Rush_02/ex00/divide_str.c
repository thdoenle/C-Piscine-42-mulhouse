/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   divide_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:29:53 by romartin          #+#    #+#             */
/*   Updated: 2022/07/31 22:34:57 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*mult_de_trois(char *str)
{
	int		i;
	int		j;
	char	*ret;

	j = 0;
	i = ft_strlen(str);
	while ((i + j) % 3 != 0)
		j++;
	ret = malloc (sizeof(char) * (i + j + 1));
	ret[i + j] = 0;
	while (i >= 1)
	{
		ret[i + j - 1] = str[i - 1];
		i--;
	}
	if (j > 0)
		ret[0] = '0';
	if (j == 2)
		ret[1] = '0';
	return (ret);
}

char	*get_grp(char *str_trois, int *k_ptr)
{
	int		j;
	char	*ret;

	ret = malloc(sizeof(char) * 4);
	j = 0;
	while (j < 3)
	{
		ret[j] = str_trois[*k_ptr];
		(*k_ptr)++;
		j++;
	}
	ret[j] = 0;
	return (ret);
}

char	**ft_norme(char *str)
{
	char	**ret;
	char	*str_trois;
	int		i;
	int		k;

	k = 0;
	i = 0;
	str_trois = mult_de_trois(str);
	ret = malloc(sizeof(*ret) * (ft_strlen(str_trois) / 3) + 1);
	while (i < (ft_strlen(str_trois) / 3))
	{
		ret[i] = get_grp(str_trois, &k);
		i++;
	}
	ret[i] = 0;
	free(str_trois);
	return (ret);
}
