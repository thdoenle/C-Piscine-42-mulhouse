/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 04:15:55 by thdoenle          #+#    #+#             */
/*   Updated: 2022/08/03 04:49:18 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(char **tab)
{
	char	*temp;

	temp = tab[0];
	tab[0] = tab[1];
	tab[1] = temp;
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
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
			if ((*cmp)(ptr[0], ptr[1]) > 0)
			{
				ft_swap(ptr);
				is_sorted = 0;
			}
			ptr++;
		}
	}
}
