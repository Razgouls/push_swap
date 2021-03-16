/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 13:48:39 by eoliveir          #+#    #+#             */
/*   Updated: 2021/02/01 13:17:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_words(char const *str, char c)
{
	int i;
	int cmp;
	int check;

	cmp = 0;
	check = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		while (str[i] && str[i] != c)
		{
			check = 1;
			i++;
		}
		(check == 1) ? cmp++ : cmp;
		check = 0;
	}
	return (cmp);
}

char			**ft_free_tab(char **strs)
{
	unsigned int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
	return (NULL);
}

static char		**ft_lancement(char const *str, char c, int *i)
{
	char	**strs;
	int		j;
	int		index;
	int		index_col;

	index = 0;
	if (!(strs = malloc((count_words(str, c) + 1) * sizeof(char *))))
		return (NULL);
	while (str[*i] && index < count_words(str, c))
	{
		index_col = 0;
		while (str[*i] && str[*i] == c)
			(*i)++;
		j = *i;
		while (str[*i] && str[*i] != c)
			(*i)++;
		if (!(strs[index] = malloc(((*i) - j + 1) * sizeof(char))))
			return (ft_free_tab(strs));
		while (j < *i)
			strs[index][index_col++] = str[j++];
		strs[index++][index_col] = 0;
	}
	strs[index] = 0;
	return (strs);
}

char			**ft_split(char const *str, char c)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	if (c != '\0')
		return (ft_lancement(str, c, &i));
	else
		return (ft_lancement(str, '\0', &i));
}
