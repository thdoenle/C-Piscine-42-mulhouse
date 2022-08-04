/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 04:15:55 by thdoenle          #+#    #+#             */
/*   Updated: 2022/08/03 04:23:05 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **tab)
{
	char	*temp;

	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
}

int	ft_is_greater(char *s1, char *s2)
{
	while (*s1 == *s2 && *s1)
	{
		s1++;
		s2++;
	}
	if (*s1 > *s2)
		return (1);
	return (0);
}

void	ft_sort_string_tab(char **tab)
{
	int		is_sorted;
	char	**ptr;

	is_sorted = 0;
	while (!is_sorted)
	{
		is_sorted = 1;
		ptr = tab;
		while (ptr[0] && ptr[1])
		{
			if (ft_is_greater(ptr[0], ptr[1]))
			{
				ft_swap(ptr);
				is_sorted = 0;
			}
			ptr++;
		}
	}
}
