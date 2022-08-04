/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:24:37 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/20 08:35:15 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	i2;

	i = 0;
	while (dest[i])
		i++;
	i2 = 0;
	while (src[i2] && i2 < nb)
	{
		dest[i] = src[i2];
		i++;
		i2++;
	}
	dest[i] = 0;
	return (dest);
}
