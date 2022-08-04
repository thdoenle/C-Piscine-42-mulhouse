/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ale-roux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 09:40:20 by ale-roux          #+#    #+#             */
/*   Updated: 2022/07/24 23:32:17 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		find_sol(char tab[11][11], int i, int n);
void	print_sol(char tab[11][11], int n);

void	print_easteregg(void)
{
	write(1, "        ###      ########   ####       #### ", 45);
	write(1, "##      ##  ##       ##    ##    ####    ## ", 45);
	write(1, "     ##    ++##### ########\n", 28);
	write(1, "      ###      ###    ###   #   ##   ##   # ", 45);
	write(1, "##      ##  ##       ##    ##   ##  ##   ## ", 45);
	write(1, "     ##   ##+      ###\n", 23);
	write(1, "    ### ###         ###     #     ###     # ", 45);
	write(1, "##      ##  ##       ##    ##  ##    ##  ## ", 45);
	write(1, "     ##  ##+       ##\n", 22);
	write(1, "  ###  ###       ###        #  ##+   +##  # ", 45);
	write(1, "##      ##  ##       ########  ##    ##  ## ", 45);
	write(1, "     ##  +#######  #####\n", 25);
	write(1, "###########   ###           #  #  +++  #  # ", 45);
	write(1, "##      ##  ##       ##    ##  ##    ##  ## ", 45);
	write(1, "     ##      +###  ##\n", 22);
	write(1, "     ###    ###             #  #       #  #  ", 45);
	write(1, "##    ##   ##       ##    ##   ##  ##    ## ", 44);
	write(1, "   ##     +###    ##\n", 21);
	write(1, "    ###   ############      ####       #### ", 44);
	write(1, "  ######    #######  ##    ##    ####      ###", 47);
	write(1, "###   ######     ########\n", 26);
}

void	easter_egg(char *str, char *str2, char *str3)
{
	int	i;

	i = 0;
	while (str[i] == str2[i] && str[i])
		i++;
	if (str[i] == str2[i])
		print_easteregg();
	else
	{
		i = 0;
		while (str[i] == str3[i] && str[i])
			i++;
		if (str[i] == str3[i])
			write(2, "Money not found lel! :D \n", 25);
		else
			write(2, "Error\n", 6);
	}
}

int	arglen(char *str)
{
	int	i;
	int	error;

	i = 0;
	error = 0;
	while (str[i] && error == 0)
	{
		if (str[i] == 32 && i % 2 == 1)
			i++;
		else if (str[i] > 48 && str[i] <= 57 && i % 2 == 0)
			i++;
		else
			error = 1;
	}
	i++;
	if (i % 8 != 0 || i / 8 > 9)
		error = 1;
	else
		i = i / 8;
	if (error == 1)
		easter_egg(str, "e c o l e 4 2", "e p i t e c h");
	if (error)
		return (0);
	return (i);
}

void	cel_init(char cel[11][11], int i, char *str)
{
	int	j;
	int	k;
	int	turn;

	k = 1;
	j = 0;
	turn = 0;
	while (turn != 4)
	{
		if (turn == 0)
			cel[0][k] = str[j];
		else if (turn == 1)
			cel[i + 1][k] = str[j];
		else if (turn == 2)
			cel[k][0] = str[j];
		else
			cel[k][i + 1] = str[j];
		k++;
		if (k == i + 1)
		{
			k = 1;
			turn++;
		}
		j = j + 2;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	char	cel[11][11];

	if (argc != 2)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	i = arglen(argv[1]);
	if (i > 0)
	{
		cel_init(cel, i, argv[1]);
		if (find_sol(cel, 0, i))
			print_sol(cel, i);
		else
			write(2, "Error\n", 6);
	}
}
