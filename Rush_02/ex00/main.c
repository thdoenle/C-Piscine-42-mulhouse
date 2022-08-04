/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkerbidi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 09:32:00 by jkerbidi          #+#    #+#             */
/*   Updated: 2022/07/31 22:50:52 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	init_tabs(char *name, char ***u_ptr, char ***t_ptr, char ***p_ptr)
{
	char	**keys;
	char	**values;

	if (parse_dict(name, &keys, &values))
		return (-1);
	*u_ptr = fill_tab_unit(keys, values);
	*t_ptr = fill_tab_tens(keys, values);
	*p_ptr = fill_tab_power(keys, values);
	return (0);
}

char	*get_non_zero_number(char *number)
{
	while (*number == '0')
		number++;
	if (ft_strlen(number) > 39)
		return (0);
	return (number);
}

int	ft_puterror(char *str)
{
	ft_putstr(str);
	return (0);
}

void	free_tabs(char **grp3, char **units, char **tens, char **powers)
{
	if (grp3)
		free_tab(grp3);
	free_tab(units);
	free_tab(tens);
	free_tab(powers);
}

int	main(int argc, char **argv)
{
	char	**units;
	char	**tens;
	char	**powers;
	char	*name;
	char	**grp3;

	if (check_error(argc, argv))
		return (ft_puterror("Error\n"));
	if (argc == 3)
		name = argv[1];
	else
		name = "numbers.dict";
	if (get_non_zero_number(argv[argc - 1]) == 0
		|| init_tabs(name, &units, &tens, &powers))
		return (ft_puterror("Dict Error\n"));
	if (ft_is_zero(argv[argc - 1]))
		ft_putstr(units[0]);
	grp3 = ft_norme(get_non_zero_number(argv[argc - 1]));
	print_number(grp3, units, tens, powers);
	free_tabs(grp3, units, tens, powers);
	ft_putchar('\n');
	return (0);
}
