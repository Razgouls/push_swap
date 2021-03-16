/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:19:06 by eoliveir          #+#    #+#             */
/*   Updated: 2020/12/02 13:53:30 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa_left(t_format *f, long long n, char c, char hexa)
{
	int				length;

	length = ft_convert_hexa_len(n);
	if (f->width > length && f->precision < length && f->precision != 0)
	{
		(n < 0 && c == '0') ? (ft_putchar_fd('-', 1)) : NULL;
		f->length += ft_write_s_z(c, f->width - length) + length;
	}
	else if (n < 0 && f->precision >= length)
	{
		f->length += ft_write_s_z(c, f->width - f->precision - 1);
		ft_putchar_fd('-', 1);
		f->length += ft_write_s_z('0', f->precision - length + 1) + length;
	}
	else if (n >= 0 && f->precision >= length)
	{
		f->length += ft_write_s_z(c, f->width - f->precision);
		f->length += ft_write_s_z('0', f->precision - length) + length;
	}
	else if (f->width > length && f->precision == 0)
		f->length += ft_write_s_z(c, f->width - length) + length;
	else
		f->length += length;
	(n < 0) ? (ft_convert_hexa(n * -1, hexa)) : (ft_convert_hexa(n, hexa));
}

void	ft_print_hexa_right(t_format *f, long long n, char c, char h)
{
	int				length;
	int				tmp;

	tmp = 0;
	if (n < 0)
		tmp = -1;
	length = ft_convert_hexa_len(n);
	if (f->precision >= length)
	{
		(n < 0) ? (ft_putchar_fd('-', 1)) : NULL;
		f->length += ft_write_s_z('0', f->precision - length + tmp);
		(n < 0) ? (ft_convert_hexa((n * -1), h)) : (ft_convert_hexa(n, h));
		f->length += ft_write_s_z(c, f->width - f->precision - tmp) + length;
	}
	else
	{
		ft_convert_hexa(n, h);
		if (f->width > length && f->precision < length && f->precision != 0)
			f->length += ft_write_s_z(c, f->width - length) + length;
		else if (f->width > length && f->precision == 0)
			f->length += ft_write_s_z(c, f->width - length) + length;
		else
			f->length += length;
	}
}
