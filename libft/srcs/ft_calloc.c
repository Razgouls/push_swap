/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 10:23:06 by eoliveir          #+#    #+#             */
/*   Updated: 2021/02/01 13:16:54 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*tmp;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	else
	{
		if (!(tmp = malloc(nmemb * size)))
			return (0);
		ft_memset(tmp, 0, nmemb * size);
	}
	return (tmp);
}
