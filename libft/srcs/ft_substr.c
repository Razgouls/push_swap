/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 11:29:59 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/27 09:09:09 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new_str;
	unsigned int	i;
	unsigned int	tmp;

	i = start;
	tmp = 0;
	if (!s || (start > ft_strlen(s)))
		return (ft_strdup(""));
	else if (start + len <= ft_strlen(s))
	{
		if (!(new_str = malloc(len + 1)))
			return (NULL);
	}
	else if ((!(new_str = malloc(ft_strlen(s) - start + 1))))
		return (NULL);
	while (tmp < len)
	{
		new_str[tmp] = s[i];
		i++;
		tmp++;
	}
	new_str[tmp] = '\0';
	return (new_str);
}
