/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 19:51:29 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/16 19:52:31 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	main(void)
{
	write(1, "5, 3\n", 5);
	rush(5, 3);
	write(1, "\n5, 1\n", 6);
	rush(5, 1);
	write(1, "\n1, 1\n", 6);
	rush(1, 1);
	write(1, "\n1, 5\n", 6);
	rush(1, 5);
	write(1, "\n4, 4\n", 6);
	rush(4, 4);
}