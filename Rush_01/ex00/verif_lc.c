/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_lc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: velbling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:33:29 by velbling          #+#    #+#             */
/*   Updated: 2022/07/24 20:56:28 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	verif_reverse_line(char tab[11][11], int i, int n)
{
	int		j;
	int		view;
	int		verif;
	char	c;
	char	highest;

	view = 0;
	j = n;
	verif = 0;
	c = n + 48;
	highest = '0';
	while (j >= 1)
	{
		if (tab[i][j] > highest)
		{
			view++;
			highest = tab[i][j];
		}
		j--;
	}
	if (view + 48 != tab[i][n + 1])
		return (0);
	return (1);
}

int	verif_line(char tab[11][11], int i, int n)
{
	int		j;
	int		view;
	int		verif;
	char	c;
	char	highest;

	view = 0;
	j = 1;
	verif = 0;
	c = n + 48;
	highest = '0';
	while (j <= n)
	{
		if (tab[i][j] > highest)
		{
			view++;
			highest = tab[i][j];
			if (highest == c)
				j = n;
		}
		j++;
	}
	if (view + 48 != tab[i][0])
		return (0);
	return (verif_reverse_line(tab, i, n));
}

int	verif_reverse_col(char tab[11][11], int i, int n)
{
	int		j;
	int		view;
	int		verif;
	char	c;
	char	highest;

	view = 0;
	j = n;
	verif = 0;
	c = n + 48;
	highest = '0';
	while (j >= 1)
	{
		if (tab[j][i] > highest)
		{
			view++;
			highest = tab[j][i];
		}
		j--;
	}
	if (view + 48 != tab[n + 1][i])
		return (0);
	return (1);
}

int	verif_col(char tab[11][11], int i, int n)
{
	int		j;
	int		view;
	int		verif;
	char	c;
	char	highest;

	view = 0;
	j = 1;
	verif = 0;
	c = n + 48;
	highest = '0';
	while (j <= n)
	{
		if (tab[j][i] > highest)
		{
			view++;
			highest = tab[j][i];
			if (highest == c)
				j = n;
		}
		j++;
	}
	if (view + 48 != tab[0][i])
		return (0);
	return (verif_reverse_col(tab, i, n));
}
