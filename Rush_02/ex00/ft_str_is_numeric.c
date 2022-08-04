/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerbidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 15:32:10 by jkerbidi          #+#    #+#             */
/*   Updated: 2022/07/19 15:50:39 by jkerbidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_numeric(char *str);

int	ft_str_is_numeric(char *str)
{
	int	result;
	int	i;

	i = 0;
	result = 1;
	while (*(str + i) != '\0')
	{
		if (*(str + i) < 48 || *(str + i) > 57)
			result = 0;
		i++;
	}
	return (result);
}
