/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 12:58:51 by eoliveir          #+#    #+#             */
/*   Updated: 2021/02/01 13:17:22 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int		on_separator(char *charset, char c)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		count_words(char *str, char *charset)
{
	int i;
	int cmp;
	int check;

	cmp = 0;
	check = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && on_separator(charset, str[i]) == 1)
			i++;
		while (str[i] && on_separator(charset, str[i]) == 0)
		{
			check = 1;
			i++;
		}
		(check == 1) ? cmp++ : cmp;
		check = 0;
	}
	return (cmp);
}

char	**ft_lancement(char *str, char *charset)
{
	char	**strs;
	int		i;
	int		j;
	int		index;
	int		index_col;

	i = 0;
	j = 0;
	index = 0;
	strs = malloc((count_words(str, charset) + 1) * sizeof(char *));
	while (str[i] && index < count_words(str, charset))
	{
		index_col = 0;
		while (str[i] && on_separator(charset, str[i]) == 1)
			i++;
		j = i;
		while (str[i] && on_separator(charset, str[i]) == 0)
			i++;
		strs[index] = malloc((i - j + 1) * sizeof(char));
		while (j < i)
			strs[index][index_col++] = str[j++];
		strs[index++][index_col] = 0;
	}
	strs[index] = 0;
	return (strs);
}

char	**ft_split_multi(char *str, char *charset)
{
	if (str == NULL)
		return (NULL);
	if (charset != NULL)
		return (ft_lancement(str, charset));
	else
		return (ft_lancement(str, ""));
}
