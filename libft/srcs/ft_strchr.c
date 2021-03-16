/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:19:09 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/16 18:38:51 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			*tmp_s;

	tmp_s = (char *)s;
	i = 0;
	while (s[i])
	{
		if (tmp_s[i] == c)
			return (tmp_s + i);
		i++;
	}
	if (c == 0)
		return (tmp_s + i);
	return (0);
}
