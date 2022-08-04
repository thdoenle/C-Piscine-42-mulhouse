/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 17:40:34 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/20 11:43:02 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_in(char *s1, char *s2)
{
	while (*s1 == *s2 && *s2)
	{
		s1++;
		s2++;
	}
	if (*s2 == 0)
		return (1);
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	if (*to_find == 0)
		return (str);
	while (*str)
	{
		if (ft_str_is_in(str, to_find))
			return (str);
		str++;
	}
	return (0);
}
