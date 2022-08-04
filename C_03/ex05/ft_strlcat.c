/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 21:16:11 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/19 22:41:47 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *src)
{
	unsigned int	len;

	len = 0;
	while (src[len])
		len++;
	return (len);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	ret;

	ret = ft_strlen(src);
	if (!size)
		return (ret);
	ret++;
	i = 0;
	while (i < size - 1 && dest[i])
	{
		i++;
		ret++;
	}
	if (dest[i] == 0)
		ret--;
	while (i < size - 1 && *src)
	{
		dest[i] = *src;
		i++;
		src++;
		dest[i] = 0;
	}
	return (ret);
}
