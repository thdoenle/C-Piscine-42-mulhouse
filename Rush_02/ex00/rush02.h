/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/31 17:43:39 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/31 21:31:38 by amouly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_strlen(char *s);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_is_wspace(char c);
int		ft_is_printable(char c);
int		ft_is_zero(char *str);
char	*ft_strcpy_malloc(char *dest, char *src);
int		ft_str_is_numeric(char *str);
char	**ft_norme(char *str);

char	get_next_char(int fd);
int		free_dict(char **keys, char **values);
void	free_tab(char **tab);
int		alloc_init_dict(char ***k_ptr, char ***v_ptr, int nb_l);
char	*str_append(char *str, char c);
int		add_empty_str(char **s_ptr);
int		parse_key(int fd, char **key, char *c_ptr);
int		parse_value(int fd, char **value, char *c_ptr);
int		parse_dict(char *name, char ***k_ptr, char ***v_ptr);
int		calc_nb_lines(char *name);
int		sort_dict(char **keys, char **values);

char	**fill_tab_unit(char **keys, char **values);
char	**fill_tab_tens(char **keys, char **values);
char	**fill_tab_power(char **keys, char **values);

int		check_error(int argc, char **argv);
void	rush(int argc, char **argv);
void	print_grp3(char *nbr, char **tens, char **units, int power);
void	print_number(char **grp3, char **units, char **tens, char **powers);
char	*mult_de_trois(char *str);

#endif
