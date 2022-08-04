/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:56:46 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/20 22:11:45 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	return (0);
}

int	ft_calc_base(char *base)
{
	int	len;
	int	i;

	len = 0;
	while (base[len])
		len++;
	if (len < 2)
		return (0);
	while (*base)
	{
		if (*base == '+' || *base == '-' || ft_isspace(*base))
			return (0);
		i = 1;
		while (base[i] && base[i] != *base)
			i++;
		if (base[i] == *base)
			return (0);
		base++;
	}
	return (len);
}

int	ft_is_in_str(char c, char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

int	ft_char_pos(char c, char *str)
{
	int	pos;

	pos = 0;
	while (str[pos] != c)
		pos++;
	return (pos);
}

int	ft_atoi_base(char *str, char *base)
{
	int	b_len;
	int	nb;
	int	sign;

	b_len = ft_calc_base(base);
	if (b_len == 0)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	nb = 0;
	while (ft_is_in_str(*str, base))
	{
		nb = nb * b_len + ft_char_pos(*str, base);
		str++;
	}
	return (nb * sign);
}
