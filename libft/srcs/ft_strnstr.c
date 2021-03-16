/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:21:17 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/24 09:16:15 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	char			*tmp_big;
	int				cmp;
	int				len_tmp;

	cmp = 0;
	i = 0;
	tmp_big = (char *)big;
	len_tmp = ft_strlen(little);
	if (len_tmp == 0)
		return (tmp_big);
	while (i < len && tmp_big[i])
	{
		if (tmp_big[i] == little[cmp])
			cmp++;
		else if (cmp > 0)
		{
			i -= cmp;
			cmp = 0;
		}
		if (cmp == len_tmp)
			return (tmp_big + i - cmp + 1);
		i++;
	}
	return (0);
}
