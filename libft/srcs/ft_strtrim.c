/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:50:21 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/20 18:49:12 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inside_set(char const *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		dep;
	size_t	i;
	size_t	fin;
	char	*new_str;

	i = 0;
	dep = 0;
	if (!s1)
		return (NULL);
	fin = ft_strlen(s1) - 1;
	while (s1[i] && ft_inside_set(set, s1[i]))
		i++;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	while (s1[fin] && ft_inside_set(set, s1[fin]))
		fin--;
	if (!(new_str = malloc(fin - i + 2)))
		return (0);
	while (s1[i] && i <= fin)
		new_str[dep++] = s1[i++];
	new_str[dep] = '\0';
	return (new_str);
}
