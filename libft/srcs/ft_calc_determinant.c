/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_determinant.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/10 17:30:13 by eoliveir          #+#    #+#             */
/*   Updated: 2021/01/10 17:30:33 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_calc_determinant(double a, double b, double c)
{
	double	det;

	det = (b * b) - (4 * a * c);
	return (det);
}
