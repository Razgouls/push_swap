/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_new_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 00:46:36 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/19 13:04:13 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_len_new_base(int nb, int len_base)
{
	int				cmp;

	cmp = 0;
	if (nb < 0)
	{
		cmp++;
		nb *= -1;
	}
	while (nb >= len_base)
	{
		nb /= len_base;
		cmp++;
	}
	return (++cmp);
}
