/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:19:32 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/29 00:19:33 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_u_left(t_format *f, unsigned int n, char c)
{
	int				length;

	length = ft_lennumber_u(n);
	if (f->width > length && f->precision < length && f->precision != 0)
		f->length += ft_write_s_z(c, f->width - length) + length;
	else if (f->precision >= length)
	{
		f->length += ft_write_s_z(c, f->width - f->precision);
		f->length += ft_write_s_z('0', f->precision - length) + length;
	}
	else if (f->width > length && f->precision == 0)
		f->length += ft_write_s_z(c, f->width - length) + length;
	else
		f->length += length;
	ft_putnbr_fd_u(n, 1);
}

void	ft_print_u_right(t_format *f, unsigned int n, char c)
{
	int				length;

	length = ft_lennumber_u(n);
	if (f->precision >= length)
	{
		f->length += ft_write_s_z('0', f->precision - length);
		ft_putnbr_fd_u(n, 1);
		f->length += ft_write_s_z(c, f->width - f->precision) + length;
		return ;
	}
	ft_putnbr_fd_u(n, 1);
	if (f->width > length && f->precision < length && f->precision != 0)
		f->length += ft_write_s_z(c, f->width - length) + length;
	else if (f->width > length && f->precision == 0)
		f->length += ft_write_s_z(c, f->width - length) + length;
	else
		f->length += length;
}
