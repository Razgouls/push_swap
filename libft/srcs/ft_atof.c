/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/08 14:44:33 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/19 12:58:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double	ft_atof(const char *str)
{
	int			neg;
	int			point;
	unsigned	pos;
	double		res;

	res = 0.0;
	pos = 1;
	point = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if ((neg = *str == '-') || *str == '+')
		str++;
	while ((*str >= '0' && *str <= '9') || (*str == '.' && !point))
	{
		if (point)
			pos *= 10;
		if (*str == '.')
			point = 1;
		else
			res = res * 10.0f + (double)(*str - '0');
		str++;
	}
	return ((neg ? -res : res) / pos);
}
