/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 08:43:58 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/17 09:42:30 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (s1[i] && i < n)
		i++;
	while (s2[j] && i + j + 1 < n)
	{
		s1[i + j] = s2[j];
		j++;
	}
	if (i != n)
		s1[i + j] = '\0';
	return (i + ft_strlen(s2));
}
