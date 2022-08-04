/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerbidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 18:08:17 by jkerbidi          #+#    #+#             */
/*   Updated: 2022/07/31 20:08:44 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_strcpy_malloc(char *dest, char *src)
{
	int		i;
	int		len_str;
	char	*ret;

	i = 0;
	len_str = ft_strlen(src);
	ret = malloc(sizeof(char) * (len_str + 1));
	while (src[i] != '\0')
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	dest = ret;
	return (dest);
}
