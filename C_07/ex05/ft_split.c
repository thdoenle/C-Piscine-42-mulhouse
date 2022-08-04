/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thdoenle <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:11:21 by thdoenle          #+#    #+#             */
/*   Updated: 2022/07/28 14:53:30 by thdoenle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_sep(char c, char *charset)
{
	while (*charset && c != *charset)
		charset++;
	if (c == *charset)
		return (1);
	return (0);
}

int	ft_count_words(char *str, char *charset)
{
	int	nb;
	int	lws;
	int	is_sep;

	nb = 0;
	lws = 1;
	while (*str)
	{
		is_sep = ft_is_sep(*str, charset);
		if (is_sep == 0 && lws)
			nb++;
		if (is_sep)
			lws = 1;
		else
			lws = 0;
		str++;
	}
	return (nb);
}

char	*ft_word_dup(char **word, char *charset)
{
	int		len;
	char	*copy;
	char	*ptr;

	len = 0;
	while (!ft_is_sep((*word)[len], charset))
		len++;
	copy = malloc(sizeof(*copy) * (len + 1));
	if (copy == 0)
		return (0);
	ptr = copy;
	while (!ft_is_sep(**word, charset))
	{
		*ptr = **word;
		(*word)++;
		ptr++;
	}
	*ptr = 0;
	return (copy);
}

char	**ft_split(char *str, char *charset)
{
	int		nb_w;
	int		i;
	char	**strs;

	nb_w = ft_count_words(str, charset);
	strs = malloc(sizeof(*strs) * (nb_w + 1));
	if (strs == 0)
		return (0);
	i = 0;
	while (i < nb_w)
	{
		while (ft_is_sep(*str, charset))
			str++;
		strs[i] = ft_word_dup(&str, charset);
		i++;
	}
	strs[i] = 0;
	return (strs);
}
