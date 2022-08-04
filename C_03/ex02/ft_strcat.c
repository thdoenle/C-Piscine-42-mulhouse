/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:09:30 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/19 14:24:05 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	unsigned int	i;
	unsigned int	i2;

	i = 0;
	while (dest[i])
		i++;
	i2 = 0;
	while (src[i2])
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = 0;
	return (dest);
}
