/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:50:11 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/18 12:59:26 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *str)
{
	unsigned int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	src_len;
	unsigned int	i;

	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	i = 0;
	while (i < size - 1 && i < src_len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (src_len);
}
