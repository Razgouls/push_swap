/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <elie.oliveir@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 07:17:09 by eoliveir          #+#    #+#             */
/*   Updated: 2021/04/01 08:09:42 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_sqrt(int nb)
{
	int			j;

	j = 0;
	if (nb < 1)
		return (0);
	while (j * j < nb && j <= 46340)
		j++;
	if (j * j == nb)
		return (j);
	else if (j * j > nb)
		return (j - 1);
	return (0);
}
