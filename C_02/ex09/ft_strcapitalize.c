/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:18:13 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/19 17:14:34 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_charlowcase(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c += 32;
}

void	ft_charupcase(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c -= 32;
}

int	ft_is_alpha_num(char c)
{
	if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	char	*ret;

	ret = str;
	while (*str)
	{
		if (ft_is_alpha_num(*str))
		{
			ft_charupcase(str);
			str++;
			while (ft_is_alpha_num(*str))
			{
				ft_charlowcase(str);
				str++;
			}
		}
		else
			str++;
	}
	return (ret);
}
