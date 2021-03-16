/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 21:50:39 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/28 21:50:46 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_percent_left(t_format *f, char p_c, char c)
{
	int				length_totale;

	length_totale = 0;
	if (f->width > 1)
	{
		length_totale += ft_write_s_z(c, f->width - 1);
		ft_putchar_fd(p_c, 1);
		f->length += length_totale + 1;
	}
	else
	{
		ft_putchar_fd(p_c, 1);
		f->length += 1;
	}
}

void	ft_print_percent_right(t_format *f, char p_c, char c)
{
	int				length_totale;

	length_totale = 0;
	ft_putchar_fd(p_c, 1);
	if (f->width > 1)
	{
		length_totale += ft_write_s_z(c, f->width - 1);
		f->length += length_totale + 1;
	}
	else
		f->length += length_totale + 1;
}
