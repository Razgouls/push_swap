/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:28:05 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/17 09:43:12 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	char	*tmp_s;
	int		i;

	i = ft_strlen(s);
	tmp_s = (char *)s;
	while (i >= 0)
	{
		if (tmp_s[i] == c)
			return (tmp_s + i);
		i--;
	}
	return (0);
}
