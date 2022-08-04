/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:56:46 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/28 11:32:32 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_isspace(char c);
int	ft_calc_base(char *base);
int	ft_is_in_str(char c, char *str);
int	ft_char_pos(char c, char *str);
int	ft_atoi_base(char *str, char *base, int b_len);

int	ft_init_str(char **str, int nbr, int b_len, int is_neg)
{
	int	i;

	i = 0;
	if (nbr <= 0)
		i++;
	is_neg = 0;
	if (nbr < 0)
		is_neg = 1;
	while (nbr)
	{
		nbr /= b_len;
		i++;
	}
	*str = malloc(sizeof(**str) * (i + 1));
	if (*str == 0)
		return (0);
	if (is_neg)
		**str = '-';
	(*str)[i] = 0;
	return (i);
}

char	*ft_itoa_base(int nbr, char *base, int b_len)
{
	int		i;
	int		is_neg;
	char	*str;

	is_neg = 0;
	if (nbr < 0)
		is_neg = 1;
	i = ft_init_str(&str, nbr, b_len, is_neg);
	if (i == 0)
		return (0);
	while (i > 1 || (i > 0 && !is_neg))
	{
		i--;
		if (is_neg)
			str[i] = base[-(nbr % b_len)];
		else
			str[i] = base[nbr % b_len];
		nbr /= b_len;
	}
	return (str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int	bf_len;
	int	bt_len;

	bf_len = ft_calc_base(base_from);
	bt_len = ft_calc_base(base_to);
	if (bt_len == 0 || bf_len == 0)
		return (0);
	return (ft_itoa_base(
			ft_atoi_base(nbr, base_from, bf_len), base_to, bt_len));
}
