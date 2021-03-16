/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eoliveir <eoliveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 00:18:46 by eoliveir          #+#    #+#             */
/*   Updated: 2020/11/29 00:18:48 by eoliveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_d_left_aux(t_format *f, int n, char c, int length)
{
	f->length += ft_write_s_z(c, f->width - f->precision - 1);
	ft_putchar_fd('-', 1);
	f->length += ft_write_s_z('0', f->precision - length + 1) + length;
	ft_putnbr_fd((n * -1), 1);
}

void	ft_print_d_left(t_format *f, int n, char c, int length)
{
	if (f->width > length && f->precision < length && f->precision != 0)
	{
		if (c == '0' && n < 0)
			ft_putchar_fd('-', 1);
		f->length += ft_write_s_z(c, f->width - length) + length;
		(n < 0 && c == '0') ? (ft_putnbr_fd(n * -1, 1)) : (ft_putnbr_fd(n, 1));
		return ;
	}
	else if (n < 0 && f->precision >= length)
	{
		ft_print_d_left_aux(f, n, c, length);
		return ;
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
	ft_putnbr_fd(n, 1);
}

void	ft_print_d_right(t_format *f, int n, char c, int length)
{
	int				tmp;

	tmp = 0;
	(n < 0) ? (tmp = 1) : tmp;
	if (f->width > length && f->precision < length && f->precision != 0)
	{
		ft_putnbr_fd(n, 1);
		f->length += ft_write_s_z(c, f->width - length) + length;
	}
	else if (f->precision > length - 1)
	{
		(n < 0) ? (ft_putchar_fd('-', 1)) : NULL;
		f->length += ft_write_s_z('0', f->precision - length + tmp);
		(n < 0) ? (ft_putnbr_fd((n * -1), 1)) : (ft_putnbr_fd(n, 1));
		f->length += ft_write_s_z(c, f->width - f->precision - tmp) + length;
	}
	else
	{
		ft_putnbr_fd(n, 1);
		if (f->width > length && f->precision == 0)
			f->length += ft_write_s_z(c, f->width - length) + length;
		else
			f->length += length;
	}
}

int		ft_write_s_z(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_putchar_fd(c, 1);
		i++;
	}
	return (i);
}
