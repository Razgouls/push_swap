/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:19:20 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/03 09:49:10 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p_left(t_format *f, unsigned long long n, char c)
{
	int				length;

	length = ft_convert_hexa_len(n) + 2;
	if (f->width > length && f->precision <= length && f->precision != 0)
	{
		f->length += ft_write_s_z(c, f->width - length) + length;
		write(1, "0x", 2);
	}
	else if (f->precision >= length)
	{
		f->length += ft_write_s_z(c, f->width - f->precision);
		write(1, "0x", 2);
		f->length += ft_write_s_z('0', f->precision - length + 2) + length;
	}
	else
	{
		f->length += ft_write_s_z(c, f->width - length) + length;
		write(1, "0x", 2);
	}
	ft_convert_hexa(n, 'x');
}

void	ft_print_p_right(t_format *f, unsigned long long n, char c)
{
	int				length;

	length = ft_convert_hexa_len(n) + 2;
	write(1, "0x", 2);
	if (f->width > length && f->precision <= length && f->precision != 0)
	{
		ft_convert_hexa(n, 'x');
		f->length += ft_write_s_z(c, f->width - length) + length;
	}
	else if (f->precision >= length)
	{
		length -= 2;
		f->length += ft_write_s_z('0', f->precision - length);
		ft_convert_hexa(n, 'x');
		f->length += ft_write_s_z(c, f->width - f->precision) + length + 2;
	}
	else if (f->precision == 0 && n == 0)
		f->length += ft_write_s_z(c, f->width - f->precision - 2) + 2;
	else
	{
		ft_convert_hexa(n, 'x');
		f->length += ft_write_s_z(c, f->width - length) + length;
	}
}
