/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:22:12 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/28 11:10:56 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_calc_size(int tab_size, char **strs, char *sep)
{
	int	size;
	int	i;

	i = 0;
	size = 0;
	while (i < tab_size)
	{
		size += ft_strlen(strs[i]);
		i++;
		if (i < tab_size)
			size += ft_strlen(sep);
	}
	return (size + 1);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*ptr;
	char	*str;

	str = malloc(sizeof(*str) * ft_calc_size(size, strs, sep));
	if (str == 0)
		return (0);
	ptr = str;
	while (size)
	{
		ptr = ft_strcpy(ptr, *strs);
		strs++;
		size--;
		if (size)
			ptr = ft_strcpy(ptr, sep);
	}
	*ptr = 0;
	return (str);
}
