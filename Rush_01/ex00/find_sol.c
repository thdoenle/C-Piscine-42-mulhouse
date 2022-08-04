/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_sol.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:10:41 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/24 21:17:31 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	verif_line(char tab[11][11], int i, int n);
int	verif_col(char tab[11][11], int i, int n);

int	is_unique(char tab[11][11], int r, int c)
{
	char	d;
	int		i;

	d = tab[r][c];
	i = 1;
	while (i < r)
	{
		if (d == tab[i][c])
			return (0);
		i++;
	}
	i = 1;
	while (i < c)
	{
		if (d == tab[r][i])
			return (0);
		i++;
	}
	return (1);
}

int	find_sol(char tab[11][11], int i, int n)
{
	int	r;
	int	c;

	if (i == n * n)
		return (1);
	r = i / n + 1;
	c = i % n + 1;
	tab[r][c] = '1';
	while (tab[r][c] <= (char)(n + 48))
	{
		if (is_unique(tab, r, c))
		{
			if ((c != n || (c == n && verif_line(tab, r, n)))
				&& (r != n || (r == n && verif_col(tab, c, n)))
				&& find_sol(tab, i + 1, n))
				return (1);
		}
		(tab[r][c])++;
	}
	tab[r][c] = '0';
	return (0);
}
