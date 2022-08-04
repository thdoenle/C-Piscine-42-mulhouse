/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 03:13:04 by thdoenle          #+#    #+#             */
/*   Updated: 2022/08/03 03:54:17 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

int		ft_atoi(char *str);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);

void	ft_sum(int a, int b);
void	ft_sub(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
void	ft_mult(int a, int b);

#endif
